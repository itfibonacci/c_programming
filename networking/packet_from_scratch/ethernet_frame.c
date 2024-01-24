#include <stdint.h> // for u_int16_t
#include <stdio.h>

#define ETHER_ADDR_LEN 6
#define ETHER_TYPE_LEN 2
#define ETHER_HDR_LEN (ETHER_ADDR_LEN*2 + ETHER_TYPE_LEN)

struct ethernet_header {
	unsigned char destination_mac[ETHER_ADDR_LEN];
	unsigned char source_mac[ETHER_ADDR_LEN];
	u_int16_t length;
};

struct ethernet_frame {
	struct ethernet_header eth_head;
	unsigned char data[1500];
};

int main() {
	printf("Ethernet header size is: %d", ETHER_HDR_LEN);
	return 0;
}

