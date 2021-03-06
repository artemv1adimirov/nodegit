// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/giterr.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/error.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitGiterr::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "errClear", GiterrClear);
         Nan::SetMethod(object, "errLast", GiterrLast);
         Nan::SetMethod(object, "errSetOom", GiterrSetOom);
         Nan::SetMethod(object, "errSetString", GiterrSetStr);
  
    Nan::Set(target, Nan::New<String>("Giterr").ToLocalChecked(), object);
  }

  
/*
   */
NAN_METHOD(GitGiterr::GiterrClear) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

giterr_clear(
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
   * @return Error  result    */
NAN_METHOD(GitGiterr::GiterrLast) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

    const git_error * result = giterr_last(
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitError result
       to = GitError::New(result, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   */
NAN_METHOD(GitGiterr::GiterrSetOom) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

giterr_set_oom(
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
 * @param Number error_class
   * @param String string
     */
NAN_METHOD(GitGiterr::GiterrSetStr) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number error_class is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String string is required.");
  }

// start convert_from_v8 block
  int from_error_class;
  from_error_class = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_string = NULL;

  String::Utf8Value string(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_string = (const char *) malloc(string.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_string, *string, string.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_string) + string.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_string
);

giterr_set_str(
  from_error_class
,  from_string
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
     