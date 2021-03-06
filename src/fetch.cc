// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/fetch.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/fetch_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitFetch::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "initOptions", InitOptions);
  
    Nan::Set(target, Nan::New<String>("Fetch").ToLocalChecked(), object);
  }

  
/*
 * @param FetchOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitFetch::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("FetchOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_fetch_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_opts
);

    int result = git_fetch_init_options(
  from_opts
,  from_version
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
     