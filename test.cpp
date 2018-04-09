#include <iostream>
#include "Model/Camera.h"
#include "Model/Lente.h"
#include "Model/Tripe.h"
#include "Model/Flash.h"
#include "Model/ProdutoPreco.h"

using namespace std;

int main() {
//CAMERA
  Camera c1 = Camera();
  c1.setMarca("Canon");
  Camera c2 = Camera("Nikon","D7000", 130,"Full-frame");
  Camera c3 = Camera(c1);
  c3.setModelo("T3i");
  //printing
  cout << "\n\tCAMERAS:\n" << c1.getMarca() << endl;
  cout << c2.getAllInfo() << endl;
  cout << c3.getAllInfo() << endl << "**********" << endl;

//LENTE
  Lente l1 = Lente();
  l1.setMarca("Sigma");
  Lente l2 = Lente("Nikon", "Nikkor AF", 280, true, 70, 300, "1.8");
  Lente l3 = Lente(l1);
  l3.setZoom(false);
  l3.setZoom_max(18);
  l3.setAbertura("34");
  //printing
  cout << "\n\tLENTES:\n" << l1.getAllInfo() << endl;
  cout << l2.getAllInfo() << endl;
  cout << l3.getAllInfo() << endl << "**********" << endl;

//TRIPE
  Tripe t1 = Tripe();
  t1.setCarga_max(4000);
  Tripe t2 = Tripe("Manfrotto", "MKCOMPACTLT", 780, 2300);
  //printing
  cout << "\n\tTRIPES:\n" << t1.getAllInfo() << endl;
  cout << t2.getAllInfo() << endl << "**********" << endl;

//FLASH
  Flash f1 = Flash();
  f1.setMarca("Canon");
  Flash f2 = Flash("Canon", "SpeedLite", 80);
  //printing
  cout << "\n\tFLASHES:\n" << f1.getAllInfo() << endl;
  cout << f2.getAllInfo() << endl;

  return 0;
}
