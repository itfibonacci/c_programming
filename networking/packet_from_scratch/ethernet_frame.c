#include <stdint.h> // for u_int16_t
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <net/ethernet.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>

#include "get_mac.h"

#ifndef ETHER_ADDR_LEN
#define ETHER_ADDR_LEN 6
#define ETHER_TYPE_LEN 2
#define ETHER_HDR_LEN (ETHER_ADDR_LEN*2 + ETHER_TYPE_LEN)
#endif
#define ETHERTYPE_CUSTOM 0x88B5

typedef struct ethernet_header {
	unsigned char destination_mac[ETHER_ADDR_LEN];
	unsigned char source_mac[ETHER_ADDR_LEN];
	u_int16_t type;
} ethernet_header_t;

typedef struct ethernet_frame {
	struct ethernet_header eth_head;
	unsigned char data[1500];
} ethernet_frame_t;

int main() {
	unsigned char *mac_address = get_interface_mac("en0");
	printf ("mac : %02x:%02x:%02x:%02x:%02x:%02x\n", mac_address [0], mac_address [1], mac_address [2], mac_address [3], mac_address [4], mac_address [5]);
	printf("Ethernet header size is: %d\n", ETHER_HDR_LEN);
	char data[] = "Hello World!";
	ethernet_header_t cool_ethernet_header;

	memcpy(cool_ethernet_header.destination_mac, mac_address, ETHER_ADDR_LEN);
	memcpy(cool_ethernet_header.source_mac, mac_address, ETHER_ADDR_LEN);
	cool_ethernet_header.type = htons(ETHERTYPE_CUSTOM);

	// create a raw socket that will be used for sending ethernet frames
	int sock_r = socket(AF_NDRV, SOCK_RAW, 0);

	// check socket was created
	if (sock_r < 0) {
		perror("Socket");
		exit(2);
	}

	atexit((mac_address));

	return 0;
}
