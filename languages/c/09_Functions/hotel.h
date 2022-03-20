#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 225.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "*******************************"

// shows list of choices
int menu(void);

// returns number of nights desired
int getnights(void);

// calculates price form rate, nights
// and displays result
void showprice(double rate, int nights);
