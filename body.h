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

#endif BODY_H
