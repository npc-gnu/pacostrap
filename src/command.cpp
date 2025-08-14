#include <iostream>      // std::cerr, std::cout
#include <string>        // std::string
#include <vector>        // std::vector
#include <sstream>       // std::istringstream
#include <unistd.h>      // fork, execvp
#include <sys/wait.h>    // waitpid
#include <cstring>       // strdup, free

// Komut string'ini boşluklara göre ayıran yardımcı fonksiyon
std::vector<std::string> split_command(const std::string& komut) {
    std::istringstream iss(komut);  // String'i stream gibi işleriz
    std::string kelime;
    std::vector<std::string> sonuc;

    while (iss >> kelime) {         // cin gibi boşlukla ayrılan parçaları tek tek al
        sonuc.push_back(kelime);    // parçaları vektöre ekle
    }

    return sonuc;
}

// Asıl komut çalıştırma fonksiyonu: command()
void command(const std::string& komut) {
    // Komutu parçala (örneğin: "ls -l /" → {"ls", "-l", "/"})
    std::vector<std::string> args = split_command(komut);

    // Eğer komut boşsa, çalıştırma
    if (args.empty()) {
        std::cerr << "empty command" << std::endl;
        return;
    }

    // execvp için C-style (char*) array'e ihtiyaç var.
    std::vector<char*> argv;

    for (const auto& s : args) {
        argv.push_back(strdup(s.c_str()));  // std::string → char* dönüşümü (kopyalanır)
    }

    argv.push_back(nullptr);  // execvp null ile bittiğini anlamalı

    // Yeni bir çocuk işlem oluştur (fork)
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "fork() error!" << std::endl;
    } else if (pid == 0) {
        // Çocuk işlemin içindeyiz → exec ile komutu çalıştır
        execvp(argv[0], argv.data());

        // Eğer exec başarısız olursa burası çalışır
        std::cerr << "execvp failed" << std::endl;
        exit(1);
    } else {
        // Ana işlem: Çocuğu bekle
        int durum;
        waitpid(pid, &durum, 0);
    }

    // strdup ile kopyalanan stringleri temizle
    for (char* ptr : argv) {
        free(ptr);
    }
}
