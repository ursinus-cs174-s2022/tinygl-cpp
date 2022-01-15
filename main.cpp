#include "tinygl-cpp.h"
# define M_PI  3.14159265358979323846

using namespace tinygl;
class MyWindow : public Window {
  public:
    MyWindow(int w, int h) : Window(w, h) {}

    void setup() override {
      std::cout << "Window size: " << width() << ", " << height() << std::endl;
    }

    void draw() override {
      background(0.2f, 0.2f, 0.2f); // parameters: r, g, b

      double r = 80;
      int N = 60;
      float cx = 200;
      float cy = 280 + 30*sin(2*M_PI*elapsedTime());
      for (int i = 0; i < N; i++) {
          color(1.0, (float)i/N, 1.0);
          double t = M_PI*0.2 + i*M_PI*(1.3)/N;
          float x = cx + r*cos(t);
          float y = cy + r*sin(t);
          circle(x, y, 5);
      }
      cy -= 2*r;
      for (int i = 0; i < N; i++) {
          color(1.0, 1.0, 1.0-(float)i/N);
          double t = M_PI/2 - i*M_PI*1.3/N;
          float x = cx + r*cos(t);
          float y = cy + r*sin(t);
          circle(x, y, 5);
      }
    }
};

int main() {
  MyWindow window(400, 400);
  window.run();
}