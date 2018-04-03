#include <iostream>
#include "Model/Camera.h"
#include "Model/Lente.h"
#include "Model/Tripe.h"
#include "Model/Flash.h"

using namespace std;

int main() {
  Camera c1 = Camera();
  c1.setMarca("Canon");
  Camera c2 = Camera("Nikon","D7000", 130,"Full-frame");
  Camera c3 = Camera(c1);
  c3.setModelo("T3i");
  //printing
  cout << c1.getMarca() << endl;
  cout << c2.getAllInfo() << endl;
  cout << c3.getAllInfo() << endl << "**********" << endl;

  Lente l1 = Lente();
  l1.setMarca("Sigma");
  Lente l2 = Lente("Nikon", "Nikkor AF", 280, true, 70, 300, 5.6);
  Lente l3 = Lente(l1);
  l3.setZoom(false);
  l3.setZoom_max(18);
  //printing
  cout << l1.getAllInfo() << endl;
  cout << l2.getAllInfo() << endl;
  cout << l3.getAllInfo() << endl << "**********" << endl;

  Tripe t1 = Tripe();
  t1.setCarga_max(4000);
  Tripe t2 = Tripe("Manfrotto", "MKCOMPACTLT", 780, 2300);
  //printing
  cout << t1.getAllInfo() << endl;
  cout << t2.getAllInfo() << endl;

  return 0;
}
