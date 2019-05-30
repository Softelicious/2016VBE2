#include <bits/stdc++.h>

using namespace std;

struct exercise{
    string name;
    int times;
};

void sort_exercises(exercise exercises[], int size_of_exercises);

int main()
{
    ifstream fromFile("U2.txt");
    ofstream toFile("U2rez.txt");
    bool foundSameName;
    int index = 0;

    string tempDelete; //kintamasiss istrinti '\n' (nauja eilute), kai skaitau visus char is failo
    string tempName;
    int tempTimes;
    tempName.resize(20); // vietos kintamajame yra 20char

    int rows;
    fromFile>>rows;
    exercise exercises[rows]; //sukuriu tiek pratimu kiek eiluciu

    fromFile.read( &tempDelete[0], 1); //  istrinu '\n'

    for(int i = 0; i < rows-1; i++){ // nes paskutinio tikrint nereikia
        foundSameName = false;
        {
            fromFile.read( &tempName[0], 20); //irasau i tempName
            fromFile>>tempTimes;
            fromFile.read( &tempDelete[0], 1);//  istrinu '\n' likusi po tempTimes irasymo
        }
        for(int j = 0; j < index; j++){ //sitam cikle visi pavadinimai yra unikalus, tai jei suranda atitikmeni su nauju pavadinimu, sudeda reiksmes
            if(exercises[j].name==tempName){
                exercises[j].times += tempTimes;
                foundSameName = true; // sitas tam, kad nekurtu unikaliu pratimu, kai rado tiesiog esama pavadinima
            }
        }
        if(!foundSameName){ //jei neranda cikle pavadinimo, sukuria unikalu pratima
            exercises[index].name = tempName;
            exercises[index].times = tempTimes;
            index++; // o sitas, kad kai ras kita karta unikalu pratima, irasytu i nauja vieta
        }
    }
    sort_exercises(exercises, index); // rusiuoja

    for(int i = 0; i < index; i++){ // iraso
        toFile<<exercises[i].name<<" "<<exercises[i].times<<endl;
    }

    return 0;
}
void sort_exercises(exercise exercises[], int size_of_exercises){
    for(int i = 0; i < size_of_exercises-1; i++){
        for(int j = i+1; j < size_of_exercises; j++){
            if(exercises[i].times < exercises[j].times){
                swap(exercises[i],  exercises[j]); //sukeicia vietom, jei desiniau esantis skaicius didesnis
            }
            else if(exercises[i].times == exercises[j].times){ // o cia jei kartai vienodi
                if(exercises[i].name > exercises[j].name)
                swap(exercises[i],  exercises[j]); //sukeicia vietom, jei desiniau esantis skaicius didesnis turetu buti auksciau pagal alfabeta
            }
        }
    }
}
