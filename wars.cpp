#include<bits/stdc++.h>
using namespace std;
class Warrior{
	private:
		string name;
		int health;
		int damage;
		int block;
	public:
		Warrior(string name,int health,int damage,int block){
			this->name=name;
			this->health=health;
			this->damage=damage;
			this->block=block;
		}
		Warrior(){
			this->name=" ";
			this->health=0;
			this->damage=0;
			this->block=0;
			
		}
		~Warrior(){
			cout<<"destroyed"<<endl;
		}
		string getName(){return this->name;
		}
		int getHealth(){return this->health;
		}
		int getDamage(){return this->damage;
		}
		int getBlock(){return this->block;
		}
		void setHealth(int health){
			this->health=max(0,health);
		}
		
};
class Battle{
	public:
	    Battle(){
	        
	    }
		void StartFight(Warrior &p1,Warrior &p2){
			Warrior p[2];
			p[0]=p1;
			p[1]=p2;
			int f=0;
			while(p[f].getHealth()){
				int damage=max(0,p[f].getDamage()-p[1-f].getBlock());
				p[1-f].setHealth(p[1-f].getHealth()-damage);
				cout<<p[1-f].getName()<<" attacked by "<<p[f].getName()<<" suffered a damage of "<<damage
				<<" and now his health is "<<p[1-f].getHealth()<<endl;
				f=1-f;
			}
			cout<<p[f].getName()<<" lost "<<p[1-f].getName()<<" won "<<endl; 
		}
};
int main(){
	Warrior thor("thor",100,30,15);
	Warrior hulk("hulk",100,20,15);
	Battle b1;
	b1.StartFight(hulk,thor);
}
