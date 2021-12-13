
#include<iostream>
using std::string;
#include"Employee.h"
#include"WorkerByHour.h"
#include"ItemWorker.h"
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  string workerName, workerLastName;
  cout << "Введите имя работника:" << endl;
  cin >> workerName;
  cout << "Введите фамилию работника:" << endl;
  cin >> workerLastName;
  WorkerByHour firstWorkerByHour(workerName, workerLastName,10,1.5);
  WorkerByHour secondWorkerByHour(workerName, workerLastName);
  ItemWorker firstItemWorker(workerName, workerLastName, 100, 500);
  ItemWorker secondItemWorker("workerName", "workerLastName");
  WorkerByHour* workers[] = {&firstWorkerByHour, &secondWorkerByHour};
  ItemWorker* iWorkers[] = {&firstItemWorker, &secondItemWorker};
  for (size_t i = 0; i < 2; i++)
  {
    workers[i]->ViewInfo();
    iWorkers[i]->ViewInfo();
  }
  cout << "Введите новое имя для первого работника по часовой ставке:" << endl;
  string newName;
  cin >> newName;
  firstWorkerByHour.SetName(newName);
  cout << "Новое имя работника: " << firstWorkerByHour.GetName() << endl;
  for (size_t i = 0; i < 2; i++)
  {
   workers[i]->~WorkerByHour();
   iWorkers[i]->~ItemWorker();
  }
  return 0;
}
