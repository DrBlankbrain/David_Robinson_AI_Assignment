#include "ParamLoader.h"

ParamLoader* ParamLoader::Instance()
{
  static ParamLoader instance;

  return &instance;
}


ParamLoader* ParamLoader::Instance2()
{
	static ParamLoader instance;

	return &instance;
}