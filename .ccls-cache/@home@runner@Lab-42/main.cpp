#include <iostream>
#include <string>

using namespace std;

class FarmAnimal{
public:
  FarmAnimal(double water_consumption);
  double getWaterConsumption();
  // ...
private:
  double water_consumption;
};


class Sheep : public FarmAnimal
{
public:
  Sheep(double given_water_consumption);
};
Sheep::Sheep(double given_water_consumption)
: FarmAnimal(1.1 * given_water_consumption / 10) {
}
// a sheep will consume about 1.1 litres of water per day per 10 kg of weigth
// a horse will consume about 6.8 litres of water per day per 100 kg of weigth
// a cow will consume about 8.6 litres of water per day per 100 kg of weigth
class Horse : public FarmAnimal
{
public:
  Horse(double given_water_consumption);
};
Horse::Horse(double given_water_consumption)
: FarmAnimal(6.8 * given_water_consumption / 100) {
}

class Cow : public FarmAnimal
{
public:
  Cow(double given_water_consumption);
};
Cow::Cow(double given_water_consumption)
: FarmAnimal(8.6 * given_water_consumption / 100) {
}

FarmAnimal::FarmAnimal(double water_consumption) {
  this->water_consumption = water_consumption;
}
double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}
class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(FarmAnimal animal);
private:
  double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() :
  total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
  return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
  total_consumption += animal.getWaterConsumption();
}
int main()
{
  ConsumptionAccumulator accumulator;
  string command;
  while(command != "quit"){
  cout << "Enter Animal" << endl;
  getline(cin, command);
  int weight;
  
  if(command.find("sheep") < command.length()){
    weight = stoi(command.substr(command.find(" ")));
    Sheep mySheep(weight);
    accumulator.addConsumption(mySheep);
  }
  if(command.find("horse") < command.length()){
    weight = stoi(command.substr(command.find(" ")));
    Horse myHorse(weight);
    accumulator.addConsumption(myHorse);
  }
  if(command.find("cow") < command.length()){
    weight = stoi(command.substr(command.find(" ")));
    Cow myCow(weight);
    accumulator.addConsumption(myCow);
  }
    }

  // read user input
  // create appropriate objects and add them to the accumulator
  cout << accumulator.getTotalConsumption();
  return 0;
  
}
