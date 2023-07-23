#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <winsock2.h>   // 윈도우에서 소켓 사용하기위한 헤더파일
    #pragma comment(lib, "ws2_32.lib")  // 윈도우에서 소켓 라이브러리 링크 지시문
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
#endif

#define PORT 8080           // 서버의 포트 번호
#define BUFFER_SIZE 1024    // 버퍼 크기 정의

int main() 
{
#ifdef _WIN32
    WSADATA wsaData;    // 1. 윈도우에서 소켓 초기화를 위한 구조체
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // winsock 라이브러리 초기화 코드
    {
        printf("Failed to initialize winsock\n");
        return -1;
    }
#endif

    int server_fd, new_socket, valread;
    struct sockaddr_in address;     // 주소 정보를 담는 구조체
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0}; // 배열의 모든요소 0으로..

    // 2. 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        perror("socket failed");
        return -1;
    }

    // 3. 소켓 옵션 설정
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt)) == SOCKET_ERROR ) {
        perror("setsockopt failed");
        return -1;
    }

    address.sin_family = AF_INET;   // IPv4 주소 체계 사용
    address.sin_addr.s_addr = INADDR_ANY;   // 모든 IP주소에서 연결 허용
    address.sin_port = htons(PORT); // 포트 번호 설정

    // 4. 소켓과 주소 바인딩
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        perror("bind failed");
        return -1;
    }

    // 5. 클라이언트의 연결 기다림
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        perror("listen failed");
        return -1;
    }

    // 6. 클라이언트의 연결 수락
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (int*)&addrlen)) == INVALID_SOCKET) {
        perror("accept faild");
        return -1;
    }

    // 7. 클라이언트와 채팅 루프
    while(1) 
    {
        memset(buffer, 0, BUFFER_SIZE);

        // 클라이언트에서 메시지 수신
        valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Client: %s\n", buffer);

        // 종료 조건 검사
        if(strcmp(buffer, "bye") == 0)
            break;
        
        // 서버에서 메시지 입력
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // 클라이언트로 메시지 전송
        send(new_socket, buffer, strlen(buffer), 0);
    }

    // 연결 종료
    closesocket(new_socket); // 클라이언트 소켓 닫기
    closesocket(server_fd); // 서버 소켓 닫기

#ifdef _WIN32
    WSACleanup();   // 윈도우에서 소켓 라이브러리 정리
#endif

    return 0;

}


