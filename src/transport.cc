// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/transport.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/transport.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/cert.h"
  #include "../include/remote.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTransport::~GitTransport() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                     }

  void GitTransport::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Transport").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "init", Init);
            Nan::SetPrototypeMethod(tpl, "smartCertificateCheck", SmartCertificateCheck);
             Nan::SetMethod(tpl, "sshWithPaths", SshWithPaths);
             Nan::SetMethod(tpl, "unregister", Unregister);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Transport").ToLocalChecked(), _constructor_template);
  }

  
/*
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitTransport::Init) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitTransport>(info.This())->GetValue()
);

    int result = git_transport_init(
  Nan::ObjectWrap::Unwrap<GitTransport>(info.This())->GetValue()
,  from_version
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param Cert cert
   * @param Number valid
   * @param String hostname
     * @return Number  result    */
NAN_METHOD(GitTransport::SmartCertificateCheck) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Cert cert is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number valid is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String hostname is required.");
  }

// start convert_from_v8 block
  git_cert * from_cert = NULL;
from_cert = Nan::ObjectWrap::Unwrap<GitCert>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_valid;
  from_valid = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_hostname = NULL;

  String::Utf8Value hostname(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_hostname = (const char *) malloc(hostname.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_hostname, *hostname, hostname.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_hostname) + hostname.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitTransport>(info.This())->GetValue()
        ,    from_cert
        ,    from_hostname
);

    int result = git_transport_smart_certificate_check(
  Nan::ObjectWrap::Unwrap<GitTransport>(info.This())->GetValue()
,  from_cert
,  from_valid
,  from_hostname
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Remote owner
   * @param Void payload
    * @param Transport callback
   */
NAN_METHOD(GitTransport::SshWithPaths) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Remote owner is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SshWithPathsBaton* baton = new SshWithPathsBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  SshWithPaths_globalPayload* globalPayload = new SshWithPaths_globalPayload;
// start convert_from_v8 block
  git_remote * from_owner = NULL;
from_owner = Nan::ObjectWrap::Unwrap<GitRemote>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->owner = from_owner;
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  SshWithPathsWorker *worker = new SshWithPathsWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("owner", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("payload", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitTransport::SshWithPathsWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->owner
        ,baton->payload
);

  int result = git_transport_ssh_with_paths(
&baton->out,baton->owner,baton->payload    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitTransport::SshWithPathsWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTransport baton->out
       to = GitTransport::New(baton->out, false  );
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
        err = Nan::Error("Method sshWithPaths has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("owner"));
      workerArguments.push(GetFromPersistent("payload"));
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
        v8::Local<v8::Object> err = Nan::Error("Method sshWithPaths has thrown an error.")->ToObject();
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

  delete (SshWithPaths_globalPayload*)baton->payload;

  delete baton;
}

   
/*
 * @param String prefix
     * @return Number  result    */
NAN_METHOD(GitTransport::Unregister) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String prefix is required.");
  }

// start convert_from_v8 block
  const char * from_prefix = NULL;

  String::Utf8Value prefix(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_prefix = (const char *) malloc(prefix.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_prefix, *prefix, prefix.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_prefix) + prefix.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_prefix
);

    int result = git_transport_unregister(
  from_prefix
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitTransportTraits>;
 