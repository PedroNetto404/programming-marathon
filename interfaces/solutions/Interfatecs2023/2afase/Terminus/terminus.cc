#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef struct {
  string ship_id;
  int change_term;
  int wait_line;
  long timet;
  double debit;
} Ship;

typedef struct {
  int term;
  vector<Ship> settle;
} Terminal;

typedef struct {
  string sid;
  int term;
  long time;
} Event;

vector<Terminal> terminals;
vector<Event> events;

void verify_gate_available() {
  Ship ship_mov;
  long mtime = LONG_MAX;

  for (auto &term_availble : terminals) {
    if (term_availble.settle.size() == 0) {
      int terml = 0;
      for (int x = 0; x < 7; x++) {
        if (terminals[x].settle.size() > 1 && terminals[x].settle[1].timet < mtime) {
          mtime = terminals[x].settle[1].timet;
          terml = x+1;
        }
      }
      if (terml > 0) {
        ship_mov = *terminals[terml-1].settle.erase(terminals[terml-1].settle.begin()+1);
        ship_mov.change_term = 1;
        term_availble.settle.push_back(ship_mov);
      }
    }
  }
}

void find_ship_on_terminals(string sid, int *term, int *pos) {
  for (int t = 0; t < terminals.size(); t++) {
    for (int s = 0; s < terminals[t].settle.size(); s++)
      if (terminals[t].settle[s].ship_id == sid) {
        *term = t+1;
        *pos = s;
      }
  }
}

double calc_debit(Ship sin, Ship sout) {
  long diftm = sout.timet - sin.timet; 
  double tgalax = (double)diftm/123.457;
  return tgalax * 4.59 + sin.debit;
}

int main (int argc, char *argv[]) {
  Terminal terminal;
  Ship ship, ship_in;
  Event evt;
  string aux;
  int terl, pos;
  long diftm;
  double tgalax, tot_debit, e, x;

  for (int i = 0; i < 7; i++) {
      terminal.term = i+1;
    terminals.push_back(terminal);
  }
  
  while (cin >> evt.sid >> evt.term >> evt.time) 
    events.push_back(evt);

  sort(events.begin(), events.end(), [&](const Event &a, const Event &b){
    return a.time < b.time;
  });

  for (Event event: events) {
    e = x = 0;
    terl = pos = -1;
    ship.debit = 0;
    ship.wait_line = ship.change_term = 0;
    ship.ship_id = event.sid;
    ship.timet = event.time;
    if (event.term > 0) {
      // arrived
      if (terminals[event.term-1].settle.size() > 0)
        ship.wait_line = 1;
      // verify if this ship already there
      find_ship_on_terminals(ship.ship_id, &terl, &pos);
      if (terl > 0) {
        ship_in = *terminals[terl-1].settle.erase(terminals[terl-1].settle.begin()+pos);
        tot_debit = calc_debit(ship_in, ship);
        ship.change_term = 1;
        ship.debit = tot_debit;
      }
      terminals[event.term-1].settle.push_back(ship);
    } else {
      // departure
      aux = "";
      find_ship_on_terminals(ship.ship_id, &terl, &pos);
      if (terl > 0) {
        ship_in = *terminals[terl-1].settle.erase(terminals[terl-1].settle.begin()+pos);
        tot_debit = calc_debit(ship_in, ship);
        ship.debit = tot_debit;
        cout << ship.ship_id << " " << fixed << setprecision(2);
        if (ship_in.wait_line) {
          aux += " E";
          e = tot_debit*0.05;
        }
        if (ship_in.change_term) {
          aux += " X";
          x = tot_debit*0.07;
        }
        cout << tot_debit+e+x << aux << endl;
      }
    }
    // verify gate available
    verify_gate_available();
  }

  return 0;
}
