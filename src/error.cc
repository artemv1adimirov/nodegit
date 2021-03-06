// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/error.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitError::~GitError() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitError::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Error").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "message", Message);
         Nan::SetPrototypeMethod(tpl, "klass", Klass);
  
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Error").ToLocalChecked(), _constructor_template);
  }

      NAN_METHOD(GitError::Message) {
      v8::Local<v8::Value> to;

       char *
         message =
         Nan::ObjectWrap::Unwrap<GitError>(info.This())->GetValue()->message;
 // start convert_to_v8 block
  if (message){
       to = Nan::New<String>(message).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitError::Klass) {
      v8::Local<v8::Value> to;

       int
         klass =
         Nan::ObjectWrap::Unwrap<GitError>(info.This())->GetValue()->klass;
 // start convert_to_v8 block
     to = Nan::New<Number>( klass);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitErrorTraits>;
 