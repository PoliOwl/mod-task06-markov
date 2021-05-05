#include "textgen.h"
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
#include <sstream>


textgen::textgen (std::ifstream& text) {
    std::string w3;
    prefix ind = prefix();
        for (int i = 0; i < NPREF; ++i) {
            std::string word;
            getline(text, word, ' ');
            ind.push_back(word);
        }
    while (getline(text, w3, ' ')) {
        if (statetab.find(ind) == statetab.end()) {
            statetab[ind] = std::vector<std::string>();
        }
        statetab[ind].push_back(w3);
        ind.push_back(w3);
        ind.pop_front();
    }
    if (statetab.find(ind) == statetab.end()) {
        statetab[ind] = std::vector<std::string>();
    }
}

textgen::textgen(const std::string& src) {
    std::stringstream text;
    text << src;
    std::string w3;
    prefix ind = prefix();
        for (int i = 0; i < NPREF; ++i) {
            std::string word;
            getline(text, word, ' ');
            ind.push_back(word);
        }
    while (getline(text, w3, ' ')) {
        if (statetab.find(ind) == statetab.end()) {
            statetab[ind] = std::vector<std::string>();
        }
        statetab[ind].push_back(w3);
        ind.push_back(w3);
        ind.pop_front();
    }
    if (statetab.find(ind) == statetab.end()) {
        statetab[ind] = std::vector<std::string>();
    }
}

std::string addPref(textgen::prefix& pref) {
    std::string str = pref[0];
    for (int i = 1; i < pref.size(); ++i) {
        str += " " + pref[i];
    }
    return str;
}

std::string textgen::generate_text() {
    srand (time(NULL));
    int firstInd = rand() % statetab.size();
    prefix ind;
    int elInd = 0;
    for (auto& el : statetab) {
        if (elInd == firstInd) {
            ind = el.first;
            break;
        }
        ++elInd;
    }
    std::string ans = addPref(ind);
    for (int i = 0; i < MAXGEN; ++i) {
        auto nexPref = statetab[ind];
        if (nexPref.size() == 0) {
            break;
        }
        auto rInd = rand() %  nexPref.size();
        auto nexSuf = nexPref[rInd];
        ans += " " + nexSuf;
        ind.push_back(nexSuf);
        ind.pop_front();
    }
    return ans;
}

std::string textgen::generate_from(const prefix& first) {
    auto ind = first;
    srand (time(NULL));
    std::string ans = addPref(ind);
    for (int i = 0; i < MAXGEN; ++i) {
        auto nexPref = statetab[ind];
        if (nexPref.size() == 0) {
            break;
        }
        auto rInd = rand() %  nexPref.size();
        auto nexSuf = nexPref[rInd];
        ans += " " + nexSuf;
        ind.push_back(nexSuf);
        ind.pop_front();
    }
    return ans;
}

std::map<textgen::prefix, std::vector<std::string>> textgen::get_prefixs() {
    return statetab;
}