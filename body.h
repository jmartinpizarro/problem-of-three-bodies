#ifndef BODY_H
#define BODY_H

// This file defines the orbital body structure

struct body {
  double gravity;
  double mass;
  double px, py;
  double vx, vy;
  double ax, ay;
};

struct node { // used for saving a pair of positions
  int px;
  int py;
};

struct path {
  node* previous_positions;// will save the last ten positions of an orbital body

  path() {
    previous_positions = new node[10]; // save memory for 10 positions
  }

  ~path() {
    delete[] previous_positions; // free memory automatically
  }
};

#endif // BODY_H
