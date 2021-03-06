// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITFILTERLIST_H
#define GITFILTERLIST_H
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "async_baton.h"
#include "nodegit_wrapper.h"
#include "promise_completion.h"

extern "C" {
#include <git2.h>
}

#include "../include/typedefs.h"

// Forward declaration.
struct git_filter_list {
};

using namespace node;
using namespace v8;

class GitFilterList;

struct GitFilterListTraits {
  typedef GitFilterList cppClass;
  typedef git_filter_list cType;

  static const bool isDuplicable = false;
  static void duplicate(git_filter_list **dest, git_filter_list *src) {
     Nan::ThrowError("duplicate called on GitFilterList which cannot be duplicated");
   }

  static const bool isFreeable = true;
  static void free(git_filter_list *raw) {
    ::free(raw); // :: to avoid calling this free recursively
   }
};

class GitFilterList : public
  NodeGitWrapper<GitFilterListTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitFilterListTraits>;
   public:
    static void InitializeComponent (v8::Local<v8::Object> target);

 

  private:
    GitFilterList()
      : NodeGitWrapper<GitFilterListTraits>(
           "A new GitFilterList cannot be instantiated."
       )
    {}
    GitFilterList(git_filter_list *raw, bool selfFreeing, v8::Local<v8::Object> owner = v8::Local<v8::Object>())
      : NodeGitWrapper<GitFilterListTraits>(raw, selfFreeing, owner)
    {}
    ~GitFilterList();
 };

#endif
