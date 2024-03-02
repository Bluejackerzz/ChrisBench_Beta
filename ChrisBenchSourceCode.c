#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <tchar.h>
#include <errno.h>
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h> 
#include <limits.h>
#endif

struct flooding{
    double a[1024];
}*temp;

void changeLog(){
    system("cls");
    printAnimation("\n    ChangeLog   \n");
    printf("V1.7.1\n");
    printf("- Change logic code for the deletion of older bench file\n");
    printf("- Fixing minor logic/code issue\n\n");

    printf("v1.7\n");
    printf("- Adding option to delete older Version\n");
    printf("- Fixing Minor Issues\n");
    printf("- i still finding the solution to resolve the filesize read bug\n\n");

    printf("v1.6.9\n");
    printf("- Adding option to proceed whenever user try to benchmark.\n");
    printf("- Fixing minor issue, with the benchmark\n\n");

    printf("v1.6.8.1\n");
    printf("- fix delete bug, user experience bug whenever they try to delete file\n");
    printf("- change Number Test logic, so it takes longer to load.\n");
    printf("- User now can try memory test.\n");
    printf("- Theres still a filesize and delete bug, whenever user done testing with the, file read test\n");

    printf("press Enter to continue...");
    while (getchar() != '\n');
    getch();
    return mainClone();
}

void deleteOldVersion(){
    // const char *old_exe_filename_1 = "ChrisBenchV1.5.1.exe";
    // const char *old_exe_filename_2 = "ChrisBenchV1.6.0[BUGGED].exe";
    // const char *old_exe_filename_3 = "ChrisBenchV1.6.8.1.exe";
    // const char *old_exe_filename_4 = "ChrisBenchV1.6.8(RILFIX).exe";
   const char *filenames[] = {
        "ChrisBenchV1.5.1.exe",
        "ChrisBenchV1.6.0[BUGGED].exe",
        "ChrisBenchV1.6.8.1.exe",
        "ChrisBenchV1.6.8(RILFIX).exe",
        "ChrisBenchV1.7.exe"
    };
    const int num_files = sizeof(filenames) / sizeof(filenames[0]);
    FILE *file_pointers[num_files];
    char pilih;
        system("cls");
        printf("Welcome to Chris BenchMark.\n");
        printf("\nDo you want to delete old Benchmark Version? (Y/N) : ");
        while (getchar() != '\n');
        scanf("%c", &pilih);       

    for (int i = 0; i < num_files; i++) {
        file_pointers[i] = fopen(filenames[i], "r");
        if (file_pointers[i] == NULL) {
            system("cls");
            printf("Welcome to Chris BenchMark.\n");
            Sleep(700);
            printf("\nFile Read Error!\n");
            Sleep(700);
            printf("Theres No older version of this BenchMark\n");
            Sleep(700);
            return mainClone();     
        }
    }
    
   for (int i = 0; i < num_files; i++) {
        if (file_pointers[i] != NULL) {
            fclose(file_pointers[i]);
        }
    }

    if (pilih == 'Y' || pilih == 'y') {
        system("cls");
        Sleep(700);
        int result = remove("ChrisBenchV1.5.1.exe");
        int result1 = remove("ChrisBenchV1.6.0[BUGGED].exe");
        int result2 = remove("ChrisBenchV1.6.8.1.exe");
        int result3 = remove("ChrisBenchV1.6.8(RILFIX).exe");
        printf("Removing old BenchMark. \n");
        Sleep(700);
        if(result == 0) {
            Sleep(700);
            printf("File has been Deleted.\n");
            return mainClone();
        } 
        else{
            Sleep(700);
            perror("Error Deleting File");
        }
            Sleep(700);
        return mainClone();

   }else if (pilih == 'N' || pilih == 'n') {
        system("cls");
        Sleep(700);
        printf("older version Will not be Deleted.\n");
        Sleep(700);
        return mainClone();

   } else {
       system("cls");
       Sleep(700);
       printf("Invalid Input\n");
       Sleep(700);
       return deleteOldVersion();
   }
}

void freeMemory(struct flooding* temp) {
    free(temp);
}

long get_file_size(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1L;
    }

    fseek(fptr, 0L, SEEK_END);
    long file_size_bytes = ftell(fptr);
    fclose(fptr);

    if (file_size_bytes == -1L) {
        perror("Error getting file size");
        return -1L; 
    }

    return file_size_bytes;
}

void memTest(){
    int second;
    char pilih;
    system("cls");
    printf("Welcome To Chris BenchMark.\n");
    Sleep(500);
    printAnimation("\nDisclaimer!\n");
    Sleep(500);
    printf("This process is funny and not so recommended.\n");
    Sleep(500);
    printf("but if you still want to try, just try it.\n");
    Sleep(500);
    printf("It won't hurt ur pc.\n\n");
    Sleep(500);

    printf("Do you still want to Proceed? (Y/N) : ");
    while (getchar() != '\n');
    scanf("%c",&pilih);

    if (pilih == 'Y' || pilih == 'y') {
        system("cls");
        printf("Welcome to Chris BenchMark.");
        Sleep(500);
        printf("\nPlease Enter the amount of times you want to enter (Second) : ");
        scanf("%d",&second);
        Sleep(500);

        time_t start_time = time(NULL); 
        double x = sizeof(struct flooding);
        for(int i = 0 ; i <= 3; i++){

            while (1) {
                temp = (struct flood *)malloc(sizeof(struct flooding));
                x=x+1024;

                if (temp == NULL){
                time_t end_time = time(NULL);
                double time_elapsed_seconds = difftime(end_time, start_time); 
                system("cls");
                printf("\nTime Elapsed: %lf\n", time_elapsed_seconds);
                printf("Memory Full\n");
                Sleep(500);
                system("cls");
                while(getchar() != '\n');
                return mainClone();
                freeMemory(temp);
                }

                time_t current_time = time(NULL);
                double elapsed_seconds = difftime(current_time, start_time);

                if (elapsed_seconds >= second){ 
                time_t end_time = time(NULL);
                double time_elapsed_seconds = difftime(end_time, start_time);
                system("cls");
                Sleep(700);
                printf("\nTime Elapsed: %lf \n", time_elapsed_seconds);
                Sleep(700);
                printf("Well Done!, Your PC can Handle it!. HEHE\n");
                Sleep(700);
                printf("Press Enter to Continue...\n");
                while (getchar() != '\n')
                getch();
                return mainClone();
                freeMemory(temp);
                }
            }
        }
    }

    else if(pilih == 'N' || pilih == 'n') {
       system("cls");
       Sleep(700);
       printAnimation("PUSSY!");
       Sleep(700);
       return mainClone();
    }
    else{
       system("cls");
       Sleep(700);
       printf("Invalid input\n");
       Sleep(700);
       return memTest();
    }
}

void numberTest(){
    double angka;
    char pilih;
    const load = 20;

    system("cls");
    printf("Welcome To Chris BenchMark.\n");
    Sleep(500);
    printf("Number Above 100 may Result in longer bench time.\n");
    Sleep(500);

    printf("\nDo you want to proceed? (Y/N) : ");
    while (getchar() != '\n');
    scanf("%c",&pilih);

    if (pilih == 'Y' || pilih == 'y'){
        system("cls");
        printf("Welcome to Chris BenchMark.\n");
        Sleep(500);
        printf("\nMasukan Jumlah Angka : ");
        scanf("%lf",&angka);

        clock_t start = clock();  

        double angkaHasil = angka * 15;
        int proccessing = 0;
	    int proccessed = 1;

	        for(double i = 0; i < angkaHasil; i++){
		        if(proccessed == proccessing) {
                    system("cls");
                    printf("Welcome To Chris BenchMark\n\n");
			        printf("[");
			        char loading[50] = "";
			    for(int j = 0 ; j < proccessed; j++) {
				    strcat(loading, "|");
                }
			        printf("%20s", loading);
			        printf("]\n");
                    printf("This might take a while...");
			        proccessed++;
		    }
		    proccessing = (int) (i / angkaHasil * load); 
		    Sleep(250);
        
        }

        clock_t end = clock();
        double time_elapsed_seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

        system("cls");
        printf("\nTime Elapsed : %lf\n", time_elapsed_seconds);
        printf("Press Enter to Continue...\n");
        while (getchar() != '\n');
        getch();
        system("cls");

        return mainClone();
    }  
    else if(pilih == 'N' || pilih == 'n') {
       system("cls");
       Sleep(500);
       printf("Back to menu..");
       Sleep(500);
       return mainClone();
    }
    else{
       system("cls");
       Sleep(700);
       printf("Invalid input\n");
       Sleep(700);
       return numberTest();
    }

}

void fileRead(){
    int level;
    char pilih;

    system("cls");
    printf("Welcome to Chris BenchMark.\n");

    Sleep(500);

    printf("This benchmark will create a file & read to test the compilers..\n");

    printAnimation("Disclaimer!\n");
        Sleep(500);
        printf("Do not Enter Level above 6 if you have storage left below < 26GB\n");
        printf("\nDo you want to proceed? (Y/N) : ");
        while (getchar() != '\n');
        scanf("%c", &pilih);

    if (pilih == 'Y' || pilih == 'y'){
        system("cls");
        printf("Welcome to Chris BenchMark.\n");
        Sleep(500);

        printAnimation("Disclaimer!\n");
        Sleep(500);
        printf("Do not Enter Level above 6 if you have storage left below < 26GB\n");
        printf("\nEnter Bench Level : ");

        scanf("%d",&level);

        system("cls");
        Sleep(500);
        printf("Testing now... ");
        Sleep(500);

        clock_t start = clock(); 

        FILE *fptr = fopen("ChrisBenchTestFile.txt","w");
        if (fptr == NULL){
            printf("File Create Error! \n");
            return 1;
        }
        for(int i  = 0 ; i <= level ; i++){
            for(int i = 0 ; i <= 150000; i++ ){
            fprintf(fptr,"👌👀👌👀👌👀👌👀👌👀 good shit go౦ԁ sHit👌 thats ✔ some good👌👌shit right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌Good shitsauce me the FUCK up 🍕🍅🍕🍅🍕🍅🍕🍅🍕🍅 cheesy shit cheesy sHit🍕 thats ✔ some cheesy🍕🍕shit right🍕🍕th 🍕 ere🍕🍕🍕 right✔there ✔✔if i do ƽaү so my selｆ 🍴 i say so 🍴 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🍴 🍕🍕 🍕НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🍕 🍕🍕 🍕 🍴 🍕 🍅🍅🍅 🍕🍕Cheesy shit 👌🎩👓🎩👍🎩👓🎩👍🎩 euphoric logic !euphoric loGic👌 thats ✔ some euphoric👌💻 logic right👌💻there👌👍👌 Carl 🔭 Sagan🌌💫if i do ƽaү so gentlemen 💯 i say so 💯 thats euPhoric logic right there Richard 📒 Dawkins🎩 (chorus: socrates died for this shit) mMMMMᎷМ💯 👌👓👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌🎩 👌 💯 👌 👓🎩🎩🎩 👍👌euphoric logic slam me the FUCK uP 👌👀👌👀👌👀👌👀👌👀 john cena JOhN cEna👌 john ✔ cena john👌👌cena john👌👌cena👌👌👌 john✔cena ✔✔u can't see me if I do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌John ceNa POTENTIALLY sign me the FUCK up 👋👀👋👀👋👀👋👀👋👀 average shit modera̷̶te sHit 👋 thats some ALright 👋👋shit right 👋👋 th 👋 ere 👋👋👋 right 🆗 there 🆗 if i do ƽaү so my selｆ🆗 i say so 🆗 that could be what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ 🆗 👋 👋👋НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ 👋 👋👋 👋 🆗 👋 👀 👀 👀 👋👋Not outstanding shit 👌👽👌👽👌👽 ayy lmao ayyy lmao good lmao👌 thats ✔ some ayyy👌👌lamayo right👌👌there👌👌👌 right✔there ✔✔if i do LMAO so my self 💯 i ayyy so 💯 thats what im probing about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌AAAYYYYyyyyYYYYYyyyyyyʸʸʸʸʸʸʸʸ👌 👌👌 👌 💯 👌 👽👽👽👌👌ayy lmao 🐸♊️🐸♊️🐸♊️🐸♊️🐸♊️ good memes go౦ԁ mEmes🐸 thats 🔫🔫some good🐸🐸memes right🐸🐸th 🐸 ere🐸🐸🐸 right🔫there 🔫🔫if i do ƽaү so my selｆ ❓❗️👟👟❓❗️ i say so ❓❗️👟👟❓❗️ thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ❓❗️👟👟❓❗️ 🐸🐸 🐸НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🐸 🐸🐸 🐸 ❓❗️👟👟❓❗️ 🐸 ♊️ ♊️ ♊️🐸🐸Good memes 💩🐃💩🐃💩🐃💩🐃💩🐃 bull shit bull sHit💩 thats ✖️ some bull💩💩shit right💩💩th 💩 ere💩💩💩 right✖️there ✖️✖️if i do ƽaү so my selｆ ‼️ i say so ‼️ thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ‼️ 💩💩 💩HO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ💩 💩💩 💩 ‼️ 💩 🐃 🐃 🐃 💩💩Bull shit do NOT sign me the FUCK up 👎👀👎👀👎👀👎👀👎👀 bad shit ba̷̶ ԁ sHit 👎 thats ❌ some bad 👎👎shit right 👎👎 th 👎 ere 👎👎👎 right ❌ there ❌ ❌ if i do ƽaү so my selｆ🚫 i say so 🚫 thats not what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ 🚫 👎 👎👎НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ 👎 👎👎 👎 🚫 👎 👀 👀 👀 👎👎Bad shit 👌👀👌👀👌👀👌👀👌👀 good shitposting go౦ԁ sHitpOsting👌 thats ✔ some good👌👌shitposting right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌Good shitposting wife me the FUCK up 👭👀👭👀👭👀👭👀👭👀 gay shit gⓐy sHit👭 thats 💍 some gay👭👭shit right👭👭th 👭 ere👭👭👭 right💍there 💍💍if i do ƽaү so my selｆ 💒 i say so 💒 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💒 👭👭 👭НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👭 👭👭 👭 💒 👭 👀 👀 👀 👭👭Gay shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 💦💖💦💖💦💖💦💖💦💖 good cummies go౦ԁ cUmmIes💦 thats ✔ some good💦💦cummies right💦💦there💦💦💦 right✔there ✔✔if my 👪daddy👪 say so him self 😽 i say so 💯 thats what hes talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMМ💯 💦💦 💦НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ💦 💦💦 💦 💯 💦 💖 💖 💖 💦💦Good cummies~ friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit 👴📅👴📅👴📅👴📅👴📅 old shit 0ld sHit👴 thats 💾 some old👴👴shit right👴👴th 👴 ere👴👴👴 right💾there 💾💾if i do ƽaү so my selｆ 🕙 i say so 🕥 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🕔 👴👴 👴НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👴 👴👴 👴 🕣 👴 📅 📅 📅 👴👴Old shit 👌🏿🍆👌🏿🍆👌🏿🍆👌🏿🍆👌🏿🍆 good dick go౦ԁ dIck👌🏿 thats ✔ some good👌🏿👌🏿dick right👌🏿👌🏿there👌🏿👌🏿👌🏿 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌🏿👌🏿 👌🏿НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌🏿👌🏿👌🏿👌🏿 💯 👌🏿 🍆🍆🍆 👌🏿👌🏿Good dick 💉🔪 💉🔪💉🔪edgy shit edgY sHit 🔪thats 🔫some edgy💉💉 shit right 🔪th🔪 ere💉💉💉 right there 🚬🚬if i do ƽaү so my selｆ 🔫i say so 🔫 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🔫 🔪🔪🔪НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🔪🔪🔪 🔫 💉💉 🔪🔪 Edgy shit 👌🌃👀👌🌃👀👌🌃👀👌🌃👀👌🌃👀 cool pic co౦l pIC👌 🌃🌃🌃thats ✔ some cool👌🌃🌃👌pic right👌🌃👌there👌🌃👌🌃👌 right✔there ✔🌃✔if i do ƽaү so 🌃🌃my self 💯 i say so 💯 thats what im talking about right 🌃there right there (chorus:cool pic ) mMMMMᎷМ💯 👌👌 🌃 🌃👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌🌃🌃👌 👌 💯 👌🌃 👀 🌃👀🌃 👀 👌👌Cool pic 👌👀👌👀👌👀👌👀👌👀 neato stuff neat౦ stuff👌 thats ✔ some neato👌👌stuff right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌neato stuff 🔝👀🔝👀🔝👀🔝👀🔝👀 up votes uP voTes 🔝thats ✔ some up 🔝🔝 votes front 🔝🔝page 🔝🔝🔝right✔there ✔✔if i do vote so my self 🆙 I vote so 🆙 thats what im talking about front page front page (chorus: ᶠʳᵒᶰᵗ ᵖᵃᵍᵉ) mMMMMᎷМ🆙 🔝🔝🔝 НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🔝 🔝🔝 🔝 🆙 🔝 👀 👀 👀 🔝🔝 Up vote👌👀👌👀👌👀👌👀👌👀 good shit go౦ԁ sHit👌 thats ✔ some good👌👌shit right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌Good shitsauce me the FUCK up 🍕🍅🍕🍅🍕🍅🍕🍅🍕🍅 cheesy shit cheesy sHit🍕 thats ✔ some cheesy🍕🍕shit right🍕🍕th 🍕 ere🍕🍕🍕 right✔there ✔✔if i do ƽaү so my selｆ 🍴 i say so 🍴 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🍴 🍕🍕 🍕НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🍕 🍕🍕 🍕 🍴 🍕 🍅🍅🍅 🍕🍕Cheesy shit 👌🎩👓🎩👍🎩👓🎩👍🎩 euphoric logic !euphoric loGic👌 thats ✔ some euphoric👌💻 logic right👌💻there👌👍👌 Carl 🔭 Sagan🌌💫if i do ƽaү so gentlemen 💯 i say so 💯 thats euPhoric logic right there Richard 📒 Dawkins🎩 (chorus: socrates died for this shit) mMMMMᎷМ💯 👌👓👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌🎩 👌 💯 👌 👓🎩🎩🎩 👍👌euphoric logic slam me the FUCK uP 👌👀👌👀👌👀👌👀👌👀 john cena JOhN cEna👌 john ✔ cena john👌👌cena john👌👌cena👌👌👌 john✔cena ✔✔u can't see me if I do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌John ceNa POTENTIALLY sign me the FUCK up 👋👀👋👀👋👀👋👀👋👀 average shit modera̷̶te sHit 👋 thats some ALright 👋👋shit right 👋👋 th 👋 ere 👋👋👋 right 🆗 there 🆗 if i do ƽaү so my selｆ🆗 i say so 🆗 that could be what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ 🆗 👋 👋👋НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ 👋 👋👋 👋 🆗 👋 👀 👀 👀 👋👋Not outstanding shit 👌👽👌👽👌👽 ayy lmao ayyy lmao good lmao👌 thats ✔ some ayyy👌👌lamayo right👌👌there👌👌👌 right✔there ✔✔if i do LMAO so my self 💯 i ayyy so 💯 thats what im probing about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌AAAYYYYyyyyYYYYYyyyyyyʸʸʸʸʸʸʸʸ👌 👌👌 👌 💯 👌 👽👽👽👌👌ayy lmao 🐸♊️🐸♊️🐸♊️🐸♊️🐸♊️ good memes go౦ԁ mEmes🐸 thats 🔫🔫some good🐸🐸memes right🐸🐸th 🐸 ere🐸🐸🐸 right🔫there 🔫🔫if i do ƽaү so my selｆ ❓❗️👟👟❓❗️ i say so ❓❗️👟👟❓❗️ thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ❓❗️👟👟❓❗️ 🐸🐸 🐸НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🐸 🐸🐸 🐸 ❓❗️👟👟❓❗️ 🐸 ♊️ ♊️ ♊️🐸🐸Good memes 💩🐃💩🐃💩🐃💩🐃💩🐃 bull shit bull sHit💩 thats ✖️ some bull💩💩shit right💩💩th 💩 ere💩💩💩 right✖️there ✖️✖️if i do ƽaү so my selｆ ‼️ i say so ‼️ thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ‼️ 💩💩 💩HO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ💩 💩💩 💩 ‼️ 💩 🐃 🐃 🐃 💩💩Bull shit do NOT sign me the FUCK up 👎👀👎👀👎👀👎👀👎👀 bad shit ba̷̶ ԁ sHit 👎 thats ❌ some bad 👎👎shit right 👎👎 th 👎 ere 👎👎👎 right ❌ there ❌ ❌ if i do ƽaү so my selｆ🚫 i say so 🚫 thats not what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ 🚫 👎 👎👎НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ 👎 👎👎 👎 🚫 👎 👀 👀 👀 👎👎Bad shit 👌👀👌👀👌👀👌👀👌👀 good shitposting go౦ԁ sHitpOsting👌 thats ✔ some good👌👌shitposting right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌Good shitposting wife me the FUCK up 👭👀👭👀👭👀👭👀👭👀 gay shit gⓐy sHit👭 thats 💍 some gay👭👭shit right👭👭th 👭 ere👭👭👭 right💍there 💍💍if i do ƽaү so my selｆ 💒 i say so 💒 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💒 👭👭 👭НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👭 👭👭 👭 💒 👭 👀 👀 👀 👭👭Gay shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 🎃👻🎃👻🎃👻👻👻🎃👻 spooky shit spooky sHit🎃 thats ✔ some spooky🎃🎃shit right🎃🎃th 🎃 ere🎃🎃🎃 right✔there ✔✔if i do ƽaү so my selｆ 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 🎃🎃 🎃НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🎃 🎃 🎃 🎃 💯 🎃 👻👻 👻 🎃🎃spooky shit 💦💖💦💖💦💖💦💖💦💖 good cummies go౦ԁ cUmmIes💦 thats ✔ some good💦💦cummies right💦💦there💦💦💦 right✔there ✔✔if my 👪daddy👪 say so him self 😽 i say so 💯 thats what hes talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMМ💯 💦💦 💦НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ💦 💦💦 💦 💯 💦 💖 💖 💖 💦💦Good cummies~ friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit friendzone me the FUCK up ❤️😍❤️😍❤️😍❤️😍❤️ m'lady shit m'lady sHit❤️ thats ✔ some m'lady 😍😍shit right❤️❤️there😍😍😍 right✔there ✔✔if i do ƽaү so my self 🙇 i say so 🙇 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🙇 😍😍😍НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ😍😍😍😍 🙇 😍 ❤️ ❤️ ❤️ 😍 ❤️ M'lady shit 👴📅👴📅👴📅👴📅👴📅 old shit 0ld sHit👴 thats 💾 some old👴👴shit right👴👴th 👴 ere👴👴👴 right💾there 💾💾if i do ƽaү so my selｆ 🕙 i say so 🕥 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🕔 👴👴 👴НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👴 👴👴 👴 🕣 👴 📅 📅 📅 👴👴Old shit 👌🏿🍆👌🏿🍆👌🏿🍆👌🏿🍆👌🏿🍆 good dick go౦ԁ dIck👌🏿 thats ✔ some good👌🏿👌🏿dick right👌🏿👌🏿there👌🏿👌🏿👌🏿 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌🏿👌🏿 👌🏿НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌🏿👌🏿👌🏿👌🏿 💯 👌🏿 🍆🍆🍆 👌🏿👌🏿Good dick 💉🔪 💉🔪💉🔪edgy shit edgY sHit 🔪thats 🔫some edgy💉💉 shit right 🔪th🔪 ere💉💉💉 right there 🚬🚬if i do ƽaү so my selｆ 🔫i say so 🔫 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ🔫 🔪🔪🔪НO0ОଠＯOOＯOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🔪🔪🔪 🔫 💉💉 🔪🔪 Edgy shit 👌🌃👀👌🌃👀👌🌃👀👌🌃👀👌🌃👀 cool pic co౦l pIC👌 🌃🌃🌃thats ✔ some cool👌🌃🌃👌pic right👌🌃👌there👌🌃👌🌃👌 right✔there ✔🌃✔if i do ƽaү so 🌃🌃my self 💯 i say so 💯 thats what im talking about right 🌃there right there (chorus:cool pic ) mMMMMᎷМ💯 👌👌 🌃 🌃👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌🌃🌃👌 👌 💯 👌🌃 👀 🌃👀🌃 👀 👌👌Cool pic 👌👀👌👀👌👀👌👀👌👀 neato stuff neat౦ stuff👌 thats ✔ some neato👌👌stuff right👌👌there👌👌👌 right✔there ✔✔if i do ƽaү so my self 💯 i say so 💯 thats what im talking about right there right there (chorus: ʳᶦᵍʰᵗ ᵗʰᵉʳᵉ) mMMMMᎷМ💯 👌👌 👌НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ👌 👌👌 👌 💯 👌 👀 👀 👀 👌👌neato stuff 🔝👀🔝👀🔝👀🔝👀🔝👀 up votes uP voTes 🔝thats ✔ some up 🔝🔝 votes front 🔝🔝page 🔝🔝🔝right✔there ✔✔if i do vote so my self 🆙 I vote so 🆙 thats what im talking about front page front page (chorus: ᶠʳᵒᶰᵗ ᵖᵃᵍᵉ) mMMMMᎷМ🆙 🔝🔝🔝 НO0ОଠOOOOOОଠଠOoooᵒᵒᵒᵒᵒᵒᵒᵒᵒ🔝 🔝🔝 🔝 🆙 🔝 👀 👀 👀 🔝🔝 Up vote");
            }
        }
        fclose(fptr);

        fptr = fopen("ChrisBenchTestFile.txt","r");
        if(fptr == NULL){
            Sleep(500);
            printf("File Read Error!\n");
            Sleep(500);
            return mainClone();
        }   
    

        long file_size_bytes = get_file_size("ChrisBenchTestFile.txt");
        if (file_size_bytes == -1L) {
            Sleep(500);
            printf("Error Displaying file size!\n");
            Sleep(500);
            return mainClone();
        }
        rewind(fptr); 
    
        printf("\nPrint The file Right Now...\n");
        printf("This might take a minute or hour..\n");

        system("cls");
    
        clock_t end = clock();

        double time_elapsed_seconds = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime Elapsed : %lf\n", time_elapsed_seconds);

        double file_size_mb = file_size_bytes / (1024.0 * 1024.0);

        printf("File size: %ld MB\n", file_size_mb); 

        char pilih;
        printf("Delete Benchmark File? (Y/N) : ");
        while (getchar() != '\n');
        fclose(fptr);
        scanf("%c", &pilih);       

    if (pilih == 'Y' || pilih == 'y') {
        system("cls");
        Sleep(700);
        int result = remove("ChrisBenchTestFile.txt");
        printf("Removing ChrisBenchTestFile.txt\n");
        Sleep(700);
        if(result == 0) {
            Sleep(700);
            printf("File has been Deleted.\n");
        } 
        else{
            Sleep(700);
            perror("Error Deleting File");
        }
            Sleep(700);
        return mainClone();

   }else if(pilih == 'N' || pilih == 'n') {
        system("cls");
        Sleep(700);
        printf("File Will not be Deleted.\n");
        Sleep(700);
        printf("Check your filesize lmao");
        Sleep(700);
        return mainClone();

   } else {
       system("cls");
       Sleep(700);
       printAnimation("Invalid Input\n");
       Sleep(700);
       return mainClone();
   }
 }
    else if(pilih == 'N' || pilih == 'n') {
       system("cls");
       Sleep(500);
       printf("Back to menu..");
       Sleep(500);
       return mainClone();
    }
    else{
       system("cls");
       Sleep(700);
       printf("Invalid input\n");
       Sleep(700);
       return fileRead();
    }
}

void printAnimation(char *str)
{
    for (char *p = str; *p; p++) {
        putchar(*p);
        fflush(stdout);
        usleep(40000);
    }
    putchar('\n');
}
void deleteBench(){
    system("cls"); 
    printf("Welcome To Chris BenchMark.\n");
    Sleep(500);

    FILE *fptr = fopen("ChrisBenchTestFile.txt","r");
    if(fptr == NULL){
        Sleep(700);
        printf("\nFile Read Error!\n");
        Sleep(700);
        printf("Lu belum create ajg\n");
        Sleep(700);
        return mainClone();
    }

    fseek(fptr, 0L, SEEK_END); 
    long file_size_bytes = ftell(fptr);
    if (file_size_bytes == -1L) { 
     printf("Error determining file size!\n");
     return 1; 
    }
    rewind(fptr);

    double file_size_mb = file_size_bytes / (1024.0 * 1024.0);
    printf("File size: %ld MB\n", file_size_mb);
    char pilih;
    printf("Delete Benchmark File? (Y/N) : ");
    while (getchar() != '\n');
    fclose(fptr);
    scanf("%c", &pilih);       

   if (pilih == 'Y' || pilih == 'y') {
       system("cls");
       Sleep(700);
       int result = remove("ChrisBenchTestFile.txt");
       printf("Removing ChrisBenchTestFile.txt\n");
       Sleep(700);
       if (result == 0) {
        Sleep(700);
        printf("File has been Deleted.\n");
        } else {
        Sleep(700);
        perror("Error Deleting File");
        }
        Sleep(700);
       return mainClone();
   } else if (pilih == 'N' || pilih == 'n') {
       system("cls");
       Sleep(700);
       printf("File Will not be Deleted.\n");
       Sleep(700);
       printf("Check your filesize lmao");
       Sleep(700);
       return mainClone();
   } else {
       system("cls");
       Sleep(700);
       printf("Invalid Input\n");
       Sleep(700);
       return deleteBench();
   }
}
void startScreen(){
    printAnimation("Welcome to Chris BenchMark...");
    Sleep(700);
    system("cls");
    printAnimation("Version 1.7.1");
    Sleep(700);`
    system("cls");
    printAnimation("Created By ChristianJodiW. written in C Language\n");
    Sleep(700);
    printAnimation("Beberapa Bug Mungkin masih akan muncul ^^\n\n");
    Sleep(700);
    printAnimation("Come join us EnjoyCompany.");
    Sleep(700);
}

void mainClone(){

system("cls");
    int choice;
    printf("Welcome To Chris BenchMark.\n");
    printf("1. Number Test\n");
    printf("2. File read Test\n");
    printf("3. Memory Test\n\n");
    printf("4. Delete Bench File\n");
    printf("5. Delete Chris BenchMark Previous version\n");
    printf("6. Exit Program\n\n");
    printf("\n Press '0' to see changelog\n");
    printf("\nenter your benchmark Choices : ");
    scanf("%d",&choice);

    switch(choice){
        case 0:
        changeLog();
        break;
        case 1:
            numberTest();   
        break;
        case 2:
            fileRead();
        break;
        case 3:
        memTest();
        break;
        case 4:
        deleteBench();
        break;
        case 5:
        deleteOldVersion();
        break;
        case 6:
        system("cls");
        printAnimation("Thx For Using this Program ^^");
        Sleep(500);
        system("cls");
        printAnimation("Bye Bye!");
        exit(0);
        default:
        system("cls");
        Sleep(500);
        printf("\nInput tidak valid...\n");
        Sleep(500);
        return mainClone();
    } 

}
int main(){

    startScreen();

    system("cls");
    int choice;
    printf("Welcome To Chris BenchMark.\n");
    printf("1. Number Test\n");
    printf("2. File read Test\n");
    printf("3. Memory Test\n\n");
    printf("4. Delete Bench File\n");
    printf("5. Delete Chris BenchMark. Previous version\n");
    printf("6. Exit Program\n\n");
    printf("\n Press '0' to see changelog\n");
    printf("\nenter your benchmark Choices : ");
    scanf("%d",&choice);

    switch(choice){
        case 0:
        changeLog();
        break;
        case 1:
            numberTest();   
        break;
        case 2:
            fileRead();
        break;
        case 3:
            memTest();
        break;
        case 4:
            deleteBench();
        break;
        case 5:
            deleteOldVersion();
        break; 
        case 6:
        system("cls");
        printAnimation("Thx For Using this Program ^^");
        Sleep(500);
        system("cls");
        printAnimation("Bye Bye!");
        exit(0);
        default:
        system("cls");
        Sleep(500);
        printf("\nInput tidak valid...\n");
        Sleep(500);
        return main();
    } 
}

