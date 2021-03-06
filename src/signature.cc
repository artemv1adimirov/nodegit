// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/signature.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/time.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitSignature::~GitSignature() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                              }

  void GitSignature::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Signature").ToLocalChecked());

           Nan::SetMethod(tpl, "default", Default);
            Nan::SetPrototypeMethod(tpl, "dup", Dup);
            Nan::SetPrototypeMethod(tpl, "free", Free);
             Nan::SetMethod(tpl, "fromBuffer", FromBuffer);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "now", Now);
           Nan::SetPrototypeMethod(tpl, "name", Name);
         Nan::SetPrototypeMethod(tpl, "email", Email);
         Nan::SetPrototypeMethod(tpl, "when", When);
  
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Signature").ToLocalChecked(), _constructor_template);
  }

  
/*
  * @param Repository repo
     * @return Signature out    */
NAN_METHOD(GitSignature::Default) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
);

git_signature_default(
&  out
,  from_repo
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New(out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
     * @param Signature callback
   */
NAN_METHOD(GitSignature::Dup) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DupBaton* baton = new DupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->sig = Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  DupWorker *worker = new DupWorker(baton, callback);
  worker->SaveToPersistent("sig", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitSignature::DupWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->sig
);

  int result = git_signature_dup(
&baton->dest,baton->sig    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitSignature::DupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->dest != NULL) {
    // GitSignature baton->dest
       to = GitSignature::New(baton->dest, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    v8::Local<v8::Value> result = to;
    v8::Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      v8::Local<v8::Object> err;
      if (baton->error->message) {
        err = Nan::Error(baton->error->message)->ToObject();
      } else {
        err = Nan::Error("Method dup has thrown an error.")->ToObject();
      }
      err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
      v8::Local<v8::Value> argv[1] = {
        err
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< v8::Local<v8::Value> > workerArguments;
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        v8::Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        v8::Local<v8::Object> nodeObj = node->ToObject();
        v8::Local<v8::Value> checkValue = GetPrivate(nodeObj, Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          v8::Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        v8::Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          v8::Local<v8::String> propName = properties->Get(propIndex)->ToString();
          v8::Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        v8::Local<v8::Object> err = Nan::Error("Method dup has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        v8::Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
     */
NAN_METHOD(GitSignature::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()
);

git_signature_free(
  Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
  
/*
  * @param String buf
    * @param Signature callback
   */
NAN_METHOD(GitSignature::FromBuffer) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String buf is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FromBufferBaton* baton = new FromBufferBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_buf = NULL;

  String::Utf8Value buf(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buf = (const char *) malloc(buf.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buf, *buf, buf.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buf) + buf.length()), 0, 1);
// end convert_from_v8 block
  baton->buf = from_buf;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  FromBufferWorker *worker = new FromBufferWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("buf", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitSignature::FromBufferWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->buf
);

  int result = git_signature_from_buffer(
&baton->out,baton->buf    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitSignature::FromBufferWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitSignature baton->out
       to = GitSignature::New(baton->out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    v8::Local<v8::Value> result = to;
    v8::Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      v8::Local<v8::Object> err;
      if (baton->error->message) {
        err = Nan::Error(baton->error->message)->ToObject();
      } else {
        err = Nan::Error("Method fromBuffer has thrown an error.")->ToObject();
      }
      err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
      v8::Local<v8::Value> argv[1] = {
        err
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< v8::Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("buf"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        v8::Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        v8::Local<v8::Object> nodeObj = node->ToObject();
        v8::Local<v8::Value> checkValue = GetPrivate(nodeObj, Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          v8::Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        v8::Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          v8::Local<v8::String> propName = properties->Get(propIndex)->ToString();
          v8::Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        v8::Local<v8::Object> err = Nan::Error("Method fromBuffer has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        v8::Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
  * @param String name
   * @param String email
   * @param Number time
   * @param Number offset
     * @return Signature out    */
NAN_METHOD(GitSignature::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number time is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number offset is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email = NULL;

  String::Utf8Value email(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_email = (const char *) malloc(email.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_email, *email, email.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_email) + email.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  git_time_t from_time;
  from_time = (git_time_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_offset;
  from_offset = (int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_name
        ,    from_email
);

git_signature_new(
&  out
,  from_name
,  from_email
,  from_time
,  from_offset
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New(out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
  * @param String name
   * @param String email
     * @return Signature out    */
NAN_METHOD(GitSignature::Now) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email = NULL;

  String::Utf8Value email(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_email = (const char *) malloc(email.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_email, *email, email.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_email) + email.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_name
        ,    from_email
);

git_signature_now(
&  out
,  from_name
,  from_email
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New(out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
       NAN_METHOD(GitSignature::Name) {
      v8::Local<v8::Value> to;

       char *
         name =
         Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->name;
 // start convert_to_v8 block
  if (name){
       to = Nan::New<String>(name).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitSignature::Email) {
      v8::Local<v8::Value> to;

       char *
         email =
         Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->email;
 // start convert_to_v8 block
  if (email){
       to = Nan::New<String>(email).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitSignature::When) {
      v8::Local<v8::Value> to;

       git_time
        *
          when =
        &
          Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->when;
 // start convert_to_v8 block
  
  if (when != NULL) {
    // GitTime when
       to = GitTime::New(when, false , info.This() );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitSignatureTraits>;
 