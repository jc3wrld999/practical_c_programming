

socket의 생성 과정
1. socket 생성
2. ip 주소와 port 번호 할당
3. listen
4. accept

```c++
#include <sys/socket.h>
int socket(int domain, int type, int protocol);     
int bind(int sockfd, struct sockadd *myaddr, socklen_t addrlen); 
int listen(int sockfd, int backlog);                            
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); 
```

