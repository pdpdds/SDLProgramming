//
//  ConfigFile.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__ConfigFile__
#define __Arkanoid__ConfigFile__

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

typedef struct value {
    string filename;
    int maxFrame;
    int frameDelay;
    int frameWidth;
    int frameHeight;
    int animationColumns;
    int animationDirection;
    int speed;
    int dirX;
    int health;
} Value;

class ConfigFile {
    
private:
    map<char, Value> content;
    string filename;
    
    template <typename T>
    static T String_to_T(string const &val);
    static void ExitWithError(const string &error);
    
    void RemoveComment(string &line) const;
    bool HasOnlyWhiteSpace(string &line) const;
    bool IsValidLine(string &line) const;
    bool KeyExists(char key) const;
    
    void ExtractKey(char &key, string &line) const;
    void ExtractValue(Value &value, string &line) const;
    void ExtractContents(string &line, size_t line_number);
    void Parse();
    
public:
    ConfigFile(string filename);
    Value GetValue_at_Key(char key);
    map<char, Value>::iterator map_begin(){ return content.begin(); }
    map<char, Value>::iterator map_end(){ return content.end(); }
    
};


#endif /* defined(__Arkanoid__ConfigFile__) */
