/*
C:\msys64\mingw64\bin\gcc.exe -fdiagnostics-color=always -g C:\clang\ex99-client.c -o C:\clang\ex99-client.exe -lws2_32
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <winsock2.h>           // 윈도우에서 소켓을 사용하기 위한 헤더 파일
    #pragma comment(lib, "ws2_32.lib") // 윈도우에서 소켓 라이브러리 링크 지시문
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s) // 유닉스 계열에서 소켓을 닫기 위한 매크로
#endif

#define PORT 8080               // 서버의 포트 번호
#define BUFFER_SIZE 1024        // 버퍼 크기 정의

int main() {
#ifdef _WIN32
    WSADATA wsaData;            // 윈도우에서 소켓 초기화를 위한 구조체
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize winsock\n");
        return -1;
    }
#endif

    int sock = 0, valread;
    struct sockaddr_in serv_addr;   // 서버 주소 정보를 담는 구조체
    char buffer[BUFFER_SIZE] = {0}; // 메시지를 저장할 버퍼

    // 소켓 생성
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // 주소 설정
    serv_addr.sin_family = AF_INET;         // IPv4 주소 체계 사용
    serv_addr.sin_port = htons(PORT);       // 포트 번호 설정

#ifdef _WIN32
    // IP 주소를 문자열로 변환하여 설정 (윈도우에서는 inet_addr 사용)
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
#else
    // IP 주소를 문자열로 변환하여 설정 (유닉스 계열에서는 inet_pton 사용)
    if (inet_pton(AF_INET, "127.0.0.1", &(serv_addr.sin_addr)) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
#endif

    // 서버에 연결
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // 서버와의 채팅
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // 클라이언트에서 메시지 입력
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // 종료 조건 검사
        if (strcmp(buffer, "bye") == 0) {
            send(sock, buffer, strlen(buffer), 0); // 'bye' 메시지 전송
            break;
        }

        // 서버로 메시지 전송
        send(sock, buffer, strlen(buffer), 0);

        // 서버에서 메시지 수신
        valread = recv(sock, buffer, BUFFER_SIZE, 0);
        printf("Server: %s\n", buffer);
    }

    // 연결 종료
    closesocket(sock); // 소켓 닫기

#ifdef _WIN32
    WSACleanup(); // 윈도우에서 소켓 라이브러리 정리
#endif

    return 0;
}
