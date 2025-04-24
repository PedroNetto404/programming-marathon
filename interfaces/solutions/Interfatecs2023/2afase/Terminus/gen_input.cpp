#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

#define TERMINALS 7
#define CT 4.59
#define TG 123.457
#define TUPPER 9876859
#define TDOWN  1235438
#define NSHIPS 5
#define A 65
#define Z 90
#define N0 48 
#define N9 57
#define SHIPS 100
#define NEVTS 10
#define RANDN ((double)rand()/RAND_MAX)
#define TDEC 3.

using namespace std;

long tupper;
long tdown;
double tdec;
int nevts;

typedef struct {
  string ss;
  int term;
  long time;
} Event;

vector<long> term_init;
vector<string> spaceship_ids, spaceships_att;
vector<Event> events;

void create_spaceship_ids(int n) {
  string nid;
  char aux;

  for (int i = 0; i < n; i++) {
    nid = "";
    for (int j = 0; j < 3; j++) {
      aux = A + rand() % (Z-A);
      nid += string(1, aux);
    }
    nid += "-";
    for (int j = 0; j < 4; j++) {
      aux = N0 + rand() % (N9-N0);
      nid += string(1, aux);
    }
    spaceship_ids.push_back(nid);
  }
}

double process_arg(string argname, int argc, char *argv[]) {
  for(int i = 1; i < argc; i++) {
    string sarg(argv[i]);
    if (argname == sarg)
      return atof(argv[i+1]);
  }
  return -1;
}

int main (int argc, char *argv[]) {
  Event evt;
  int idx, t;
  long tt = 0;

  srand(time(NULL));

  tupper = process_arg("-TUPPER", argc, argv);
  tupper = tupper == -1 ? TUPPER : tupper;

  tdown = process_arg("-TDOWN", argc, argv);
  tdown = tdown == -1 ? TDOWN : tdown;

  nevts = process_arg("-NEVTS", argc, argv);
  nevts = nevts == -1 ? NEVTS : nevts;

  tdec = process_arg("-TDEC", argc, argv);
  tdec = tdec == -1 ? TDEC : tdec;
 
  create_spaceship_ids(SHIPS);
  // create events
  tt = tdown;
  for (int i = 0; i < nevts;) {
    tt += rand() % tupper; 
    // choose between arrived or departure
    if (rand() % 2 && spaceship_ids.size() > 0) {
      // arrived
      idx = rand() % spaceship_ids.size();
      evt.ss = spaceship_ids[idx];
      spaceship_ids.erase(spaceship_ids.begin()+idx);
      spaceships_att.push_back(evt.ss);
      evt.term = (rand() % TERMINALS) + 1;
      evt.time = tt;
      cout << evt.ss << " " << evt.term << " " << evt.time << endl; 
      events.push_back(evt);
    } else if (RANDN >= 1/exp((double)i/tdec)){
      // departure or change gate
      idx = rand() % spaceships_att.size();
      evt.ss = spaceships_att[idx];
      if (rand() % 10 > 3) { //departure
        spaceships_att.erase(spaceships_att.begin()+idx);
        spaceship_ids.push_back(evt.ss);
        evt.term = 0;
      } else { // change gate
        evt.term = (rand() % TERMINALS) + 1; 
      }
      reverse(events.begin(), events.end()) ;
      vector<Event>::iterator e = find_if(events.begin(), events.end(), [evt](Event ev) { 
          return ev.ss == evt.ss && ev.term > 0;
      });
      evt.time = tt;
      cout << evt.ss << " " << evt.term << " " << evt.time << endl;
      events.push_back(evt);
      reverse(events.begin(), events.end()) ;
    } else {
      continue;
    }
    i++;
  }  

  return 0;
}
