// ----------------------------------------------------------------------------
/**
   File: get_route.h

   System:         Linux
   Component Name: Ethanol, Netlink, getmacaddress
   Status:         Version 1.0 Release 1
   Language: C

   License: GNU Public License

   Description: Este módulo obtem um lista com as rotas configuradas no dispositivo

   Limitations: funciona somente em ambiente linux

   Function: 1) wapi_get_routes

   Thread Safe: yes

   Compiler Options: none

   Change History:            (Sometimes called "Revisions")
   Date         Author       Description
   27/05/2016   Henrique     primeiro release

*/
#ifndef __GET_ROUTE_H
#define __GET_ROUTE_H


#define ROUTE_FLAGS_UP	      0x1	    // route usable
#define ROUTE_FLAGS_GATEWAY   0x2	    // destination is a	gateway
#define ROUTE_FLAGS_HOST	    0x4	    // host entry (net otherwise)
#define ROUTE_FLAGS_REJECT	  0x8	    // host or net unreachable
#define ROUTE_FLAGS_DYNAMIC   0x10	    // created dynamically (by redirect)
#define ROUTE_FLAGS_MODIFIED  0x20	    // modified	dynamically (by	redirect)
#define ROUTE_FLAGS_DONE	    0x40	    // message confirmed
#define ROUTE_FLAGS_MASK	    0x80	    // subnet mask present
#define ROUTE_FLAGS_CLONING   0x100    // generate	new routes on use
#define ROUTE_FLAGS_XRESOLVE  0x200    // external	daemon resolves	name
#define ROUTE_FLAGS_LLINFO	  0x400    // generated by ARP	or ESIS
#define ROUTE_FLAGS_STATIC	  0x800    // manually	added
#define ROUTE_FLAGS_BLACKHOLE 0x1000   // just discard pkts (during updates)
#define ROUTE_FLAGS_CLONED	  0x2000   // this is a cloned	route

struct entrada_rotas {
  char * ifname;
  char * dest;
  char * gw;
  char * mask;
  long flags; // see "man 4 route" in a BSD platform
  int refcnt;
  int use;
  int metric;
  int mtu;
  int window;
  int irtt;
};

struct lista_rotas {
  int num_routes;
  struct entrada_rotas ** r;
};

/** returns the routing table */
struct lista_rotas * get_routes(void);

/** returns the default gateway */
char * get_default_gateway(void);

/** returns the gateway to net/mask network */
char * get_gateway(char * net, char * mask);

void free_lista_rotas(struct lista_rotas * p);

char * convert_s_addr(unsigned int v);
#endif