#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

uint32_t ntohl(uint32_t x){
	return (x<<24)|(x<<8)&(0x00ff0000)|(x>>8)&(0x0000ff00)|(x>>24);
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
