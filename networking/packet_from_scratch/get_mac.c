#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <errno.h>

#include <get_mac.h>

unsigned char *get_interface_mac(const char *interface) {
	struct ifaddrs *if_addrs = NULL;
	struct ifaddrs *if_addr = NULL;
	void *tmp = NULL;
	char buf[INET6_ADDRSTRLEN];

	unsigned char *mac_address = malloc(6 * sizeof(unsigned char));
	if (mac_address == NULL) {
		fprintf(stderr, "Failed to allocate memory for MAC address\n");
		exit(3);
	}

	if (0 == getifaddrs (&if_addrs)) {
		size_t len = sizeof(if_addr->ifa_name);
		for (if_addr = if_addrs; if_addr != NULL; if_addr = if_addr->ifa_next) {
			if (strncmp(if_addr->ifa_name, interface, len) == 0) {
				// MAC address
				if (if_addr->ifa_addr != NULL && if_addr->ifa_addr->sa_family == AF_LINK) {
					struct sockaddr_dl* sdl = (struct sockaddr_dl *)if_addr->ifa_addr;
					if (6 == sdl->sdl_alen) {
						memcpy (mac_address, LLADDR (sdl), sdl->sdl_alen);
					}
				}
				printf ("\n");
			}
		}
		freeifaddrs (if_addrs);
		if_addrs = NULL;
		return mac_address;
	} 
	else {
		printf ("getifaddrs () failed with errno = %i %s\n", errno, strerror (errno));
	}
}

int get_all_macs() {
	struct ifaddrs *if_addrs = NULL;
	struct ifaddrs *if_addr = NULL;
	void *tmp = NULL;
	char buf [INET6_ADDRSTRLEN];

	if (0 == getifaddrs (&if_addrs)) {
		for (if_addr = if_addrs; if_addr != NULL; if_addr = if_addr->ifa_next) {
			printf ("name : %s\n", if_addr->ifa_name);

			// Address
			if (if_addr->ifa_addr->sa_family == AF_INET) {
				tmp = & ( (struct sockaddr_in *)if_addr->ifa_addr)->sin_addr;
			} else {
				tmp = & ( (struct sockaddr_in6 *)if_addr->ifa_addr)->sin6_addr;
			}
			printf ("addr : %s\n", inet_ntop (if_addr->ifa_addr->sa_family, tmp, buf, sizeof (buf)));

			// MAC address
			if (if_addr->ifa_addr != NULL && if_addr->ifa_addr->sa_family == AF_LINK) {
				struct sockaddr_dl* sdl = (struct sockaddr_dl *)if_addr->ifa_addr;
				unsigned char mac [6];
				if (6 == sdl->sdl_alen) {
					memcpy (mac, LLADDR (sdl), sdl->sdl_alen);
					printf ("mac : %02x:%02x:%02x:%02x:%02x:%02x\n", mac [0], mac [1], mac [2], mac [3], mac [4], mac [5]);
				}
			}

			printf ("\n");
		}

		freeifaddrs (if_addrs);
		if_addrs = NULL;
	} 
	else {
		printf ("getifaddrs () failed with errno = %i %s\n", errno, strerror (errno));
		return -1;
	}
}
