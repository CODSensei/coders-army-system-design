#include<iostream>
#include<string>

using namespace std;

// real life car
class Car {
protected:
	string brand;
	string model;
	bool isEngineOn;
	int currentSpeed;
public:
	Car(string b, string m) {
		this->brand = b;
		this->model = m;
		isEngineOn = false;
		currentSpeed = 0;
	}

	void startEngine() {
		isEngineOn = true;
		cout << brand << " " << model << " : Engine starts with roar!" << endl;
	}

	void accelerate() {
		if (!isEngineOn){
			cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
			return;
		}
		currentSpeed += 20;
		cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" <<  endl;
	}

	void brake() {
		currentSpeed -= 20;
		if (currentSpeed < 0) currentSpeed = 0;
		cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" <<  endl;
	}

	void stopEngine() {
		isEngineOn = false;
		currentSpeed = 0;
		cout << brand << " " << model << " : Engine turned off!" << endl;
	}
};

class ManualCar: public Car {
private:
	int currentGear;
public:
	ManualCar(string b, string m): Car(b,m) {
		currentGear = 0;
	}

	void shiftGear(int gear) {
		currentGear = gear;
		cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
	}
};

class ElectricCar: public Car {
private:
	int energyLoad;
public:
	ElectricCar(string b, string m): Car(b,m) {
		energyLoad = 100;
	}

	void chargeEnergy() {
		energyLoad = 100;
		cout << brand << " " << model << " : Battery fully charged!" << endl;
	}
	
};

int main() {
	
	ManualCar* myManualCar = new ManualCar("BMW", "M5CS");

	myManualCar->startEngine();
	myManualCar->shiftGear(1);
	myManualCar->accelerate();
	myManualCar->brake();
	myManualCar->stopEngine();
	
	delete myManualCar;

	cout << "_______________________________________________" << endl;

	ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");

	myElectricCar->chargeEnergy();
	myElectricCar->startEngine();
	myElectricCar->accelerate();
	myElectricCar->brake();
	myElectricCar->stopEngine();
	
	delete myElectricCar;

	
	return 0;
}
