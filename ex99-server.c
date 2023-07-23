

/*

1. Winsock을 사용할 수 있도록 초기화(Initialize)한다. 
2. 리스닝 소켓을 생성(create)한다. 
3. IP 주소와 PORT 번호와 같은 정보를 소켓에 묶어(bind)준다.
서버가 클라이언트의 요청을 받을 수 있는 상태(listen)가 되도록 한다.
클라이언트의 요청이 들어오면 받는다(accept).
해당 서버에선 1개의 클라이언트만 받을 것이기 때문에 현재 listening 중인 서버측 소켓을 닫는다(close).
=> 모든 통신에 적용되는 단계는 아님
send/recv와 같은 함수를 통해 클라이언트와 데이터를 주고 받는다. (Do something loop)
7번 동작이 끝나면, 클라이언트와 연결된 소켓을 닫는다(close).
Winsock의 사용을 종료(cleanup, terminate)한다. (1번과 대칭되는 단계)
=> terminate라고도 한다. 

*/

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <winsock2.h>           // 윈도우에서 소켓을 사용하기 위한 헤더 파일
    #pragma comment(lib, "ws2_32.lib") // 윈도우에서 소켓 라이브러리 링크 지시문
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s) // 유닉스 계열에서 소켓을 닫기 위한 매크로
#endif

#define PORT 8080               // 서버의 포트 번호
#define BUFFER_SIZE 1024        // 버퍼 크기 정의

int main() {
#ifdef _WIN32
    WSADATA wsaData;            // 1. 윈도우에서 소켓 초기화를 위한 구조체
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize winsock\n");
        return -1;
    }
#endif

    int server_fd, new_socket, valread;
    struct sockaddr_in address;     // 주소 정보를 담는 구조체
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // 2. 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        perror("socket failed");
        return -1;
    }

    // 3. 소켓 옵션 설정
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
        perror("setsockopt failed");
        return -1;
    }

    address.sin_family = AF_INET;        // IPv4 주소 체계 사용
    address.sin_addr.s_addr = INADDR_ANY; // 모든 IP 주소에서 연결 허용
    address.sin_port = htons(PORT);      // 포트 번호 설정

    // 4. 소켓과 주소 바인딩
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        perror("bind failed");
        return -1;
    }

    // 5. 클라이언트의 연결을 기다림
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        perror("listen failed");
        return -1;
    }

    printf("Server is listening on port %d\n", PORT);

    // 6. 클라이언트의 연결을 수락
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (int*)&addrlen)) == INVALID_SOCKET) {
        perror("accept failed");
        return -1;
    }

    // 7. 클라이언트와의 채팅 루프
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // 클라이언트에서 메시지 수신
        valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Client: %s\n", buffer);

        // 종료 조건 검사
        if (strcmp(buffer, "bye") == 0)
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
    closesocket(server_fd);  // 서버 소켓 닫기

#ifdef _WIN32
    WSACleanup(); // 윈도우에서 소켓 라이브러리 정리
#endif

    return 0;
}
