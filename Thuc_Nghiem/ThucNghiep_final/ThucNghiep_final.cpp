#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

int M;

struct URL {
    string data = "";
    int* idlk = new int[M];
    int count;
};

struct HashTable {
    int key;
    URL* table = new URL[M];
};

int n;
int step;
int* move_id;
int m;
int* index;
URL url;
HashTable* Hash = nullptr;

void start() // create value.
{
    step = 0;
    //  M = 37;
    n = 1;
    m = 0;

    Hash = new HashTable;
    index = new int[M];
    move_id = new int[M];
    for (int i = 0; i < M; i++)
    {
        index[i] = 0;
        for (int j = 0; j < M; j++)
            Hash->table[i].idlk[j] = 0;
        Hash->table[i].count = 1;
        move_id[i] = 0;
    }
}

void end() //delete value
{
    delete[] move_id;
    move_id = nullptr;
    delete[] index;
    index = nullptr;


    delete[] Hash->table->idlk;
    Hash->table->idlk = nullptr;

}

int string_tokey(string S)
{
    int key = 0;
    step++;
    for (int i = 1; i < S.length(); i++)
        key += S[i] * i;
    key = int(key) % (M);
    step++;
    int i = 1;
    while (Hash->table[index[key]].data != S && index[key] != 0)
    {
        key = (key + i) % M;
        i++;
        step += 2;
    }
    step += 2;
    return key;
}
void insertParent(string S)
{
    int key = string_tokey(S);
    index[key] = n;
    Hash->table[n].data = S;
    n++;
}
void insertChild(string url1, string url2)
{
    int key1 = string_tokey(url1);
    if (index[key1] == 0)
    {
        Hash->table[n].data = url1;
        index[key1] = n;
        n++;
    }
    int key2 = string_tokey(url2);

    if (index[key2] == 0)
    {
        Hash->table[n].data = url2;
        index[key2] = n;
        n++;
    }

    int count = Hash->table[index[key1]].count;
    Hash->table[index[key1]].idlk[count] = index[key2];
    Hash->table[index[key1]].count++;
}

void insert()
{
    insertParent("https://uex.hctmute.edu.vn/my/");

    insertChild("https://uex.hctmute.edu.vn/my/", "https://utex.hcmute.edu.vn/course/view.php?id=5004"); //  CTDL
    insertChild("https://uex.hctmute.edu.vn/my/", "https://utex.hcmute.edu.vn/course/view.php?id=5256"); //nhap mon xa hoi hoc
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=5004", "https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626"); // video week 1 CTDL
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=5004", "https://utex.hcmute.edu.vn/mod/lesson/view.php?id=160581"); //video week 2  CTDL
    insertChild("https://uex.hctmute.edu.vn/my/", "https://utex.hcmute.edu.vn/course/view.php?id=8826"); //lap trinh huong doi tuong
    insertChild("https://uex.hctmute.edu.vn/my/", "https://utex.hcmute.edu.vn/course/view.php?id=11328"); //phap luat dai cuong
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=5004", "https://utex.hcmute.edu.vn/mod/lesson/view.php?id=180507"); // video week 3  CTDL
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/page/view.php?id=74202"); //video 1 PLDC
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/page/view.php?id=74217"); //video 2 PLDCC
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://www.youtube.com/watch?v=-HhoQMzLSqg"); //video 3 PLDC
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", "https://drive.google.com/file/d/15bVvDB09E89Js61FUdKdwvUftFhcTZKp/view");  //video sá»‘ CTDL
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", "https://drive.google.com/file/d/19ysA3Z4Ow7rvbBAfUWyVpue10mwYxPuC/view?usp=sharing,");
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", "https://drive.google.com/file/d/1EXZJhKsbdVG4De66efLbz_0v-P8bKBGM/view?usp=sharing,");
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", "https://drive.google.com/file/d/1gl8HcfjJx8bTQpQB-eO_vR7-8rF6khJC/view?usp=sharing");
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", " https://drive.google.com/file/d/1XfT5MEQLbqIqUfsfwOHvb8iq0xfeOIEQ/view?usp=sharing");
    insertChild("https://utex.hcmute.edu.vn/mod/lesson/view.php?id=151626", "  https://drive.google.com/file/d/1aDgPtw2fPed-aHesr73cutxMO85qsiUV/view?usp=sharing");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/pluginfile.php/470934/mod_resource/content/1/BAI%202%20LLC%20V%E1%BB%80%20PL.pdf");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/quiz/view.php?id=74223");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/forum/view.php?id=74226");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://docs.google.com/forms/d/e/1FAIpQLSe1lKn0BXhdXoV8CYKR7-LV5w-Cukfaq2Whtrhkx83Rksz6lg/viewform");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/pluginfile.php/470976/mod_resource/content/1/BAI%203%20QUY%20PHAM%20PHAP%20LUAT.pdf");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/quiz/view.php?id=74238");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://docs.google.com/forms/d/e/1FAIpQLSe1lKn0BXhdXoV8CYKR7-LV5w-Cukfaq2Whtrhkx83Rksz6lg/viewform");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/page/view.php?id=74247");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/quiz/view.php?id=74253");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/mod/forum/view.php?id=74256");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://docs.google.com/forms/d/e/1FAIpQLSe1lKn0BXhdXoV8CYKR7-LV5w-Cukfaq2Whtrhkx83Rksz6lg/viewform");
    insertChild("https://utex.hcmute.edu.vn/course/view.php?id=11328", "https://utex.hcmute.edu.vn/pluginfile.php/1215700/mod_resource/content/1/BAI%204%20QUAN%20HE%20PHAP%20LUAT.pdf");



}


void tracing(int key, int& step, int& countURL) { // Duyệt tuần tự theo chiều sâu.
    step++;
    if (index[key] != 0) {
        countURL++;
        step += 2;
        int dem = 1;
        while (dem < Hash->table[index[key]].count)
        {
            step += 3;
            int key1 = string_tokey(Hash->table[Hash->table[index[key]].idlk[dem]].data);
            tracing(key1, step, countURL);
            dem++;
        }
        Hash->table[index[key]].count = 1;
        index[key] = 0;
        step += 1;
    }
    else
        return;
}
void find_parent(int keyChild, int keyParent, int& stop) {
    if (index[keyParent] != 0)
    {
        int dem = 1;
        while (dem < Hash->table[index[keyParent]].count) {
            int key = string_tokey(Hash->table[Hash->table[index[keyParent]].idlk[dem]].data);
            if (key == keyChild)
            {
                stop = keyParent;
            }
            find_parent(keyChild, key, stop);
            dem++;
        }
    }
}
void deleteURL(int id, int& step, int& countURL, float& time_use) {
    clock_t start = clock();
    int key = string_tokey(Hash->table[id].data);

    int idele = 0;
    int keyParent = 1, stop = 0;
    int temp = step;
    clock_t start_ex = clock();
    find_parent(key, string_tokey(Hash->table[1].data), keyParent);
    clock_t end_ex = clock();
    step = temp;
    for (int i = 1; i < Hash->table[index[keyParent]].count; i++)
    {
        if (Hash->table[index[keyParent]].idlk[i] == index[key])
        {
            step += 1;
            idele = i;
            break;
        }
        step += 2;
    }
    tracing(key, step, countURL);

    if (index[keyParent] != 1)
    {
        for (int i = idele; i < Hash->table[index[keyParent]].count - 1; i++)
        {
            step += 3;
            Hash->table[index[keyParent]].idlk[i] = Hash->table[index[keyParent]].idlk[i + 1];
        }
        Hash->table[index[keyParent]].count--;
        step += 1;
    }
    step += 5;
    clock_t end = clock();
    time_use = (float)(end - start - end_ex + start_ex) / CLOCKS_PER_SEC;
}

int findStepMin(int STEP[]) {
    int min = STEP[0], indexMin = 0;
    for (int i = 1; i < 15; i++) {
        if (min >= STEP[i]) {
            min = STEP[i];
            indexMin = i;
        }
    }
    return indexMin;
}
int datontai(int CountURL[], int index[], int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (CountURL[index[i]] == CountURL[k])
            return 1;
    }
    return 0;
}

void outFile(int CountURL[], int Step[]) {
    int index[1000] = { -1 }, count = 0;
    int Continue[1000] = { 0 };
    int n = 1000;
    int* ptr = &n;
    int i = 0, min, indexMin;
    while (i < 1000) {
        min = 1000000, indexMin;
        for (int j = 0; j < 1000; j++) {
            if (min > CountURL[j] && Continue[j] == 0 && Continue[j] != CountURL[j])
            {
                min = CountURL[j];
                indexMin = j;
            }
        }
        if (datontai(CountURL, index, indexMin, count) == 0)
            index[count++] = indexMin;
        Continue[indexMin] = CountURL[indexMin];
        i++;
    }

    /* ofstream outData;
     outData.open("outfile.csv", ios::app);*/
    for (int i = 0; i < count; i++) {
        cout << "Sum URL: " << CountURL[index[i]] << "\t" << "Step: " << Step[index[i]] << endl;
    }
    return;

}

int main()
{
    int i = 0;
    int TableSize[] = { 101, 97, 89, 83, 79, 73, 71, 67, 61, 59, 53, 47, 43, 41, 37 };
    int STEP[100];
    while (i < 15) {
        M = TableSize[i];
        start();
        insert();
        STEP[i] = step;
        end();
        i++;
    }

    /*for (int i = 0; i < 15; i++) {
        cout << "size: " << TableSize[i] << "\t" << "Step: " << STEP[i] << endl;
    }
    string option;
    do {
        cout << "nhap 1 de tiep tuc: ";
        cin >> option;

    } while (option != "1");*/

    int indexMin = findStepMin(STEP);
    int id;
    i = 0;
    int CountURL[1000];
    int Step[1000];
    double TimeUse[1000];
    int ID[1000];
    float time_use;
    srand((int)time(NULL));
    while (i < 1000) {
        step = 0;
        int temp = step;
        id = 1 + rand() % (n - 2 + 1);
        start();
        insert();
        int countURL = 0;
        step = temp;
        time_use = 0;
        deleteURL(id, step, countURL, time_use);
        end();
        CountURL[i] = countURL;
        Step[i] = step;
        TimeUse[i] = time_use;
        ID[i] = id;
        i++;
    }
    int SUMStep = 0, SUMURL = 0;
    double SUMTIME = 0;
    for (int i = 0; i < 1000; i++)
    {
        cout << "ID: " << ID[i] << " \tSum URL : " << CountURL[i] << "\tSum step : " << Step[i] << "\ttime use : " << TimeUse[i] << endl;
        SUMStep += Step[i];
        SUMURL += CountURL[i];
        SUMTIME += TimeUse[i];
    }
    cout << "AVG step: " << SUMStep / 1000 << endl;
    cout << "AVG URL: " << SUMURL / 1000 << endl;
    cout << "AVG Time use: " << SUMTIME / 1000 << endl;




    outFile(CountURL, Step);


}