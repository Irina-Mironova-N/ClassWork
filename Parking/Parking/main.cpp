#include "param.h";



#define Test

struct Aeroplane {
    string id;
    string type;

};

struct Aerodrome {
    int angarCount;
    int placeCount;
    Aeroplane*** angar = nullptr;
    Aeroplane** place = nullptr;
    int* placeBuf = nullptr;

    //начальная инициализация массивов
    void startInit() {
        place = new Aeroplane * [placeCount] { nullptr };
        angar = new Aeroplane * *[angarCount];
        for (int i = 0; i < angarCount; i++) {
            angar[i] = new Aeroplane * [2]{ nullptr };
        }
        placeBuf = new int[placeCount] {0};;


    }

    //обновление очередности занятия парковочных мест после добавления самолета
    void addToBuffer(int index) {
        for (int i = 0; i < placeCount; i++) {
            if (placeBuf[i] != 0)placeBuf[i]++;
        }
        placeBuf[index] = 1;

    }

    //обновление очередности занятия парковочных мест после удаления самолета
    void removeFromBuffer(int index) {
        int n = placeBuf[index];
        for (int i = 0; i < placeCount; i++) {
            if (placeBuf[i] > n)placeBuf[i]--;
        }
        placeBuf[index] = 0;




    }

    //добавить самолет в ангар
    bool addToAngar(Aeroplane*& aeroplane) {
        if (aeroplane->type == "light") {
            for (int i = 0; i < angarCount; i++) {
                if (angar[i][0] == nullptr) {
                    angar[i][0] = aeroplane;
                    return 1;
                }
                else if (angar[i][1] == nullptr && angar[i][0]->type == "light") {
                    angar[i][1] = aeroplane;
                    return 1;
                }
            }
        }
        else if (aeroplane->type == "boing") {
            for (int i = 0; i < angarCount; i++) {
                if (angar[i][0] == nullptr && angar[i][1] == nullptr) {
                    angar[i][0] = aeroplane;
                    return 1;
                }
            }
        }
        return 0;
    }
    //удалить самолет с парковки по id (возвращает удаляемый самолет)
    Aeroplane* removeFromPlace(string id) {
        Aeroplane* aeroplane = nullptr;

        for (int i = 0; i < placeCount; i++) {
            if (place[i]->id == id) {
                aeroplane = place[i];
                place[i] = nullptr;
                removeFromBuffer(i);
                break;
            }
        }
        return aeroplane;
    }

    //добавить самолет на парковку
    bool addToPlace(Aeroplane*& aeroplane) {
        for (int i = 0; i < placeCount; i++) {
            if (place[i] == nullptr) {
                addToBuffer(i);
                place[i] = aeroplane;
                return 1;

            }
        }
        return 0;

    }

};

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    //generateAeroplane(PATH_AEROPLANE_FILE, COUNT_AEROPLANE);
    //generateAerodromeFile(PATH_AERODROM_FILE, COUNT_AERODROM);

    //вывод фаилов
#ifdef test
    string* arrrayAeroplane = readFile(PATH_AEROPLANE_FILE);
    string* arrrayAerodrom readFile(PATH_AERODROM_FILE);
    for (int i = 0; i < COUNT_AEROPLANE; i++) {
        cout << arrrayAeroplane[i] << endl;
    }
    for (int i = 0; i < COUNT_AERODROM; i++) {
        cout << arrrayAerodrom[i] << endl;
    }

#endif
    Aerodrome aero{ 3, 5 };
    aero.startInit();

}