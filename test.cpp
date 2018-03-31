#include <iostream>
#include "Model/Camera.h"

using namespace std;

int main() {
  Camera c1 = Camera();
  c1.setMarca("Canon");
  Camera c2 = Camera("Nikon","D7000","Full-frame");
  Camera c3 = Camera(c1);
  c3.setModelo("T3i");

  cout << c1.getAllInfo() << endl;
  cout << c2.getAllInfo() << endl;
  cout << c3.getAllInfo() << endl;

  return 0;
}
