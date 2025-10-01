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

	void stopEngine() {
		isEngineOn = false;
		currentSpeed = 0;
		cout << brand << " " << model << " : Engine turned off!" << endl;
	}

	virtual void accelerate() = 0;
	virtual void brake() = 0;
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

	void accelerate() {
		if (!isEngineOn){
			cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
			return;
		}
		currentSpeed += 20;
		cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" <<  endl;
	}
	
	void accelerate(int speed) {
		if (!isEngineOn){
			cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
			return;
		}
		currentSpeed += speed;
		cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" <<  endl;
	}

	void brake() {
		currentSpeed -= 20;
		if (currentSpeed < 0) currentSpeed = 0;
		cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" <<  endl;
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

	void accelerate() {
		if (!isEngineOn){
			cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
			return;
		}
		if (energyLoad <= 0){
			cout << brand << " " << model << " : NO enery left! Cannot accelerate." << endl;
			return;
		}
		energyLoad -= 10;
		currentSpeed += 10;
		cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" <<  endl;
	}

	void brake() {
		currentSpeed -= 10;
		if (currentSpeed < 0) currentSpeed = 0;
		cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" <<  endl;
	}
	
};

int main() {
	
	ManualCar* myManualCar = new ManualCar("BMW", "M5CS");

	myManualCar->startEngine();
	myManualCar->shiftGear(1);
	myManualCar->accelerate();
	myManualCar->brake();
	myManualCar->accelerate(40);
	myManualCar->brake();
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
