struct algae_position {
  int x;
  int y;
};

struct algae_position grid[32][32];
int total_x = 0, total_y = 0;

void foo18() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      total_x += grid[i][j].x;
    }
  }

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      total_y += grid[i][j].y;
    }
  }
}

void foo19() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      total_x += grid[j][i].x;
      total_y += grid[j][i].y;
    }
  }
}

void foo20() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      total_x += grid[i][j].x;
      total_y += grid[i][j].y;
    }
  }
}
