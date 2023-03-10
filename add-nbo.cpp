#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}


uint16_t ntohs(uint16_t x){
	return (x>>8)|(x<<8);
}


uint32_t ntohl(uint32_t x){
	return (x<<24)|(x<<8)&(0x00ff0000)|(x>>8)&(0x0000ff00)|(x>>24);
}



void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n = ntohs(*p); // TODO
	printf("16 bit number=0x%x\n", n);
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = ntohl(*p); // TODO
	//uint32_t n = *p;
	printf("32 bit number=0x%x\n", n);
}

int main(int argc, char* argv[]) {
    //printf("%s\n",argv[1]);
	FILE* a = fopen(argv[1],"rb");
    FILE* b = fopen(argv[2],"rb");
    uint32_t num1=0, num2=0;
    fread(&num1, sizeof(uint32_t), 1, a);
    fread(&num2, sizeof(uint32_t), 1, b);
    num1 = ntohl(num1);
    num2 = ntohl(num2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1,num1,num2,num2,num1+num2,num1+num2);

}
