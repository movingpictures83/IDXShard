#ifndef IDXSHARDPLUGIN_H
#define IDXSHARDPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class IDXShardPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "IDXShard";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
