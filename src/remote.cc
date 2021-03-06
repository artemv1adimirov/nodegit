// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/remote.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/remote_head.h"
  #include "../include/repository.h"
  #include "../include/remote_callbacks.h"
  #include "../include/proxy_options.h"
  #include "../include/strarray.h"
  #include "../include/buf.h"
  #include "../include/fetch_options.h"
  #include "../include/refspec.h"
  #include "../include/push_options.h"
  #include "../include/transfer_progress.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRemote::~GitRemote() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                                                     }

  void GitRemote::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Remote").ToLocalChecked());

           Nan::SetMethod(tpl, "addFetch", AddFetch);
             Nan::SetMethod(tpl, "addPush", AddPush);
            Nan::SetPrototypeMethod(tpl, "autotag", Autotag);
            Nan::SetPrototypeMethod(tpl, "connect", Connect);
            Nan::SetPrototypeMethod(tpl, "connected", Connected);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "createAnonymous", CreateAnonymous);
             Nan::SetMethod(tpl, "createWithFetchspec", CreateWithFetchspec);
            Nan::SetPrototypeMethod(tpl, "defaultBranch", DefaultBranch);
             Nan::SetMethod(tpl, "delete", Delete);
            Nan::SetPrototypeMethod(tpl, "disconnect", Disconnect);
            Nan::SetPrototypeMethod(tpl, "download", Download);
            Nan::SetPrototypeMethod(tpl, "dup", Dup);
            Nan::SetPrototypeMethod(tpl, "fetch", Fetch);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "getFetchRefspecs", GetFetchRefspecs);
            Nan::SetPrototypeMethod(tpl, "getPushRefspecs", GetPushRefspecs);
            Nan::SetPrototypeMethod(tpl, "getRefspec", GetRefspec);
             Nan::SetMethod(tpl, "initCallbacks", InitCallbacks);
             Nan::SetMethod(tpl, "isValidName", IsValidName);
             Nan::SetMethod(tpl, "list", List);
             Nan::SetMethod(tpl, "lookup", Lookup);
            Nan::SetPrototypeMethod(tpl, "name", Name);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "prune", Prune);
            Nan::SetPrototypeMethod(tpl, "pruneRefs", PruneRefs);
            Nan::SetPrototypeMethod(tpl, "push", Push);
            Nan::SetPrototypeMethod(tpl, "pushurl", Pushurl);
            Nan::SetPrototypeMethod(tpl, "refspecCount", RefspecCount);
             Nan::SetMethod(tpl, "setAutotag", SetAutotag);
             Nan::SetMethod(tpl, "setPushurl", SetPushurl);
             Nan::SetMethod(tpl, "setUrl", SetUrl);
            Nan::SetPrototypeMethod(tpl, "stats", Stats);
            Nan::SetPrototypeMethod(tpl, "stop", Stop);
            Nan::SetPrototypeMethod(tpl, "updateTips", UpdateTips);
            Nan::SetPrototypeMethod(tpl, "upload", Upload);
            Nan::SetPrototypeMethod(tpl, "url", Url);
            Nan::SetPrototypeMethod(tpl, "referenceList", ReferenceList);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Remote").ToLocalChecked(), _constructor_template);
  }

  
/*
 * @param Repository repo
   * @param String remote
   * @param String refspec
     * @return Number  result    */
NAN_METHOD(GitRemote::AddFetch) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String remote is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String refspec is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_remote = NULL;

  String::Utf8Value remote(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote = (const char *) malloc(remote.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote, *remote, remote.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote) + remote.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_refspec = NULL;

  String::Utf8Value refspec(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refspec = (const char *) malloc(refspec.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refspec, *refspec, refspec.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refspec) + refspec.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
        ,    from_remote
        ,    from_refspec
);

    int result = git_remote_add_fetch(
  from_repo
,  from_remote
,  from_refspec
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Repository repo
   * @param String remote
   * @param String refspec
     * @return Number  result    */
NAN_METHOD(GitRemote::AddPush) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String remote is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String refspec is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_remote = NULL;

  String::Utf8Value remote(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote = (const char *) malloc(remote.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote, *remote, remote.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote) + remote.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_refspec = NULL;

  String::Utf8Value refspec(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refspec = (const char *) malloc(refspec.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refspec, *refspec, refspec.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refspec) + refspec.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
        ,    from_remote
        ,    from_refspec
);

    int result = git_remote_add_push(
  from_repo
,  from_remote
,  from_refspec
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRemote::Autotag) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    git_remote_autotag_option_t result = git_remote_autotag(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
   * @param Number direction
   * @param RemoteCallbacks callbacks
   * @param ProxyOptions proxy_opts
   * @param Strarray custom_headers
     */
NAN_METHOD(GitRemote::Connect) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number direction is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("RemoteCallbacks callbacks is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("ProxyOptions proxy_opts is required.");
  }

  if (info.Length() == 3 || !(Nan::To<bool>(info[3]).FromJust())) {
    return Nan::ThrowError("Array, String Object, or string custom_headers is required.");
  }
  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConnectBaton* baton = new ConnectBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();
// start convert_from_v8 block
  git_direction from_direction;
  from_direction = (git_direction)  (int) info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->direction = from_direction;
// start convert_from_v8 block
  const git_remote_callbacks * from_callbacks = NULL;
from_callbacks = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->callbacks = from_callbacks;
// start convert_from_v8 block
  const git_proxy_options * from_proxy_opts = NULL;
from_proxy_opts = Nan::ObjectWrap::Unwrap<GitProxyOptions>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->proxy_opts = from_proxy_opts;
// start convert_from_v8 block
  const git_strarray * from_custom_headers = NULL;

  from_custom_headers = StrArrayConverter::Convert(info[3]);
// end convert_from_v8 block
  baton->custom_headers = from_custom_headers;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[4]));
  ConnectWorker *worker = new ConnectWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("direction", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("callbacks", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("proxy_opts", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("custom_headers", info[3]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::ConnectWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->remote
        ,baton->callbacks
        ,baton->proxy_opts
        ,baton->custom_headers
);

  int result = git_remote_connect(
baton->remote,baton->direction,baton->callbacks,baton->proxy_opts,baton->custom_headers    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::ConnectWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method connect has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("direction"));
      workerArguments.push(GetFromPersistent("callbacks"));
      workerArguments.push(GetFromPersistent("proxy_opts"));
      workerArguments.push(GetFromPersistent("custom_headers"));
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
        v8::Local<v8::Object> err = Nan::Error("Method connect has thrown an error.")->ToObject();
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
     * @return Number  result    */
NAN_METHOD(GitRemote::Connected) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    int result = git_remote_connected(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Repository repo
   * @param String name
   * @param String url
    * @param Remote callback
   */
NAN_METHOD(GitRemote::Create) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
  baton->name = from_name;
// start convert_from_v8 block
  const char * from_url = NULL;

  String::Utf8Value url(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_url = (const char *) malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_url, *url, url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
// end convert_from_v8 block
  baton->url = from_url;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("url", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::CreateWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->name
        ,baton->url
);

  int result = git_remote_create(
&baton->out,baton->repo,baton->name,baton->url    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRemote baton->out
       to = GitRemote::New(baton->out, true  );
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
        err = Nan::Error("Method create has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("name"));
      workerArguments.push(GetFromPersistent("url"));
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
        v8::Local<v8::Object> err = Nan::Error("Method create has thrown an error.")->ToObject();
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
  * @param Repository repo
   * @param String url
    * @param Remote callback
   */
NAN_METHOD(GitRemote::CreateAnonymous) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateAnonymousBaton* baton = new CreateAnonymousBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_url = NULL;

  String::Utf8Value url(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_url = (const char *) malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_url, *url, url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
// end convert_from_v8 block
  baton->url = from_url;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  CreateAnonymousWorker *worker = new CreateAnonymousWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("url", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::CreateAnonymousWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->url
);

  int result = git_remote_create_anonymous(
&baton->out,baton->repo,baton->url    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::CreateAnonymousWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRemote baton->out
       to = GitRemote::New(baton->out, true  );
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
        err = Nan::Error("Method createAnonymous has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("url"));
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
        v8::Local<v8::Object> err = Nan::Error("Method createAnonymous has thrown an error.")->ToObject();
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
  * @param Repository repo
   * @param String name
   * @param String url
   * @param String fetch
    * @param Remote callback
   */
NAN_METHOD(GitRemote::CreateWithFetchspec) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String fetch is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateWithFetchspecBaton* baton = new CreateWithFetchspecBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
  baton->name = from_name;
// start convert_from_v8 block
  const char * from_url = NULL;

  String::Utf8Value url(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_url = (const char *) malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_url, *url, url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
// end convert_from_v8 block
  baton->url = from_url;
// start convert_from_v8 block
  const char * from_fetch = NULL;

  String::Utf8Value fetch(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_fetch = (const char *) malloc(fetch.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_fetch, *fetch, fetch.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_fetch) + fetch.length()), 0, 1);
// end convert_from_v8 block
  baton->fetch = from_fetch;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[4]));
  CreateWithFetchspecWorker *worker = new CreateWithFetchspecWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("url", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("fetch", info[3]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::CreateWithFetchspecWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->name
        ,baton->url
        ,baton->fetch
);

  int result = git_remote_create_with_fetchspec(
&baton->out,baton->repo,baton->name,baton->url,baton->fetch    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::CreateWithFetchspecWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRemote baton->out
       to = GitRemote::New(baton->out, true  );
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
        err = Nan::Error("Method createWithFetchspec has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("name"));
      workerArguments.push(GetFromPersistent("url"));
      workerArguments.push(GetFromPersistent("fetch"));
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
        v8::Local<v8::Object> err = Nan::Error("Method createWithFetchspec has thrown an error.")->ToObject();
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
     * @param Buf callback
   */
NAN_METHOD(GitRemote::DefaultBranch) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DefaultBranchBaton* baton = new DefaultBranchBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->asize = 0;
  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  DefaultBranchWorker *worker = new DefaultBranchWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::DefaultBranchWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->remote
);

  int result = git_remote_default_branch(
baton->out,baton->remote    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::DefaultBranchWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->out) {
    to = Nan::New<String>(baton->out->ptr, baton->out->size).ToLocalChecked();
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
        err = Nan::Error("Method defaultBranch has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method defaultBranch has thrown an error.")->ToObject();
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

        git_buf_free(baton->out);
        free((void *)baton->out);

  delete baton;
}

  
/*
 * @param Repository repo
   * @param String name
     */
NAN_METHOD(GitRemote::Delete) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DeleteBaton* baton = new DeleteBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  DeleteWorker *worker = new DeleteWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::DeleteWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->name
);

  int result = git_remote_delete(
baton->repo,baton->name    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::DeleteWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method delete has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("name"));
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
        v8::Local<v8::Object> err = Nan::Error("Method delete has thrown an error.")->ToObject();
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
NAN_METHOD(GitRemote::Disconnect) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DisconnectBaton* baton = new DisconnectBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  DisconnectWorker *worker = new DisconnectWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::DisconnectWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->remote
);

  git_remote_disconnect(
baton->remote    );

  }
}

void GitRemote::DisconnectWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method disconnect has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method disconnect has thrown an error.")->ToObject();
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
   * @param Strarray refspecs
   * @param FetchOptions opts
     */
NAN_METHOD(GitRemote::Download) {

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("FetchOptions opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DownloadBaton* baton = new DownloadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_refspecs = NULL;

  from_refspecs = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->refspecs = from_refspecs;
// start convert_from_v8 block
  const git_fetch_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  DownloadWorker *worker = new DownloadWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("refspecs", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::DownloadWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->remote
        ,baton->refspecs
        ,baton->opts
);

  int result = git_remote_download(
baton->remote,baton->refspecs,baton->opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::DownloadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method download has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("refspecs"));
      workerArguments.push(GetFromPersistent("opts"));
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
        v8::Local<v8::Object> err = Nan::Error("Method download has thrown an error.")->ToObject();
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
     * @param Remote callback
   */
NAN_METHOD(GitRemote::Dup) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DupBaton* baton = new DupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->source = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  DupWorker *worker = new DupWorker(baton, callback);
  worker->SaveToPersistent("source", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::DupWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->source
);

  int result = git_remote_dup(
&baton->dest,baton->source    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::DupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->dest != NULL) {
    // GitRemote baton->dest
       to = GitRemote::New(baton->dest, true  );
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
   * @param Strarray refspecs
   * @param FetchOptions opts
   * @param String reflog_message
     */
NAN_METHOD(GitRemote::Fetch) {

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("FetchOptions opts is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FetchBaton* baton = new FetchBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_refspecs = NULL;

  from_refspecs = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->refspecs = from_refspecs;
// start convert_from_v8 block
  const git_fetch_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;
// start convert_from_v8 block
  const char * from_reflog_message = NULL;
    if (info[2]->IsString()) {

  String::Utf8Value reflog_message(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_reflog_message = (const char *) malloc(reflog_message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_reflog_message, *reflog_message, reflog_message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_reflog_message) + reflog_message.length()), 0, 1);
  }
  else {
    from_reflog_message = 0;
  }
// end convert_from_v8 block
  baton->reflog_message = from_reflog_message;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  FetchWorker *worker = new FetchWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("refspecs", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("reflog_message", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::FetchWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->remote
        ,baton->refspecs
        ,baton->opts
        ,baton->reflog_message
);

  int result = git_remote_fetch(
baton->remote,baton->refspecs,baton->opts,baton->reflog_message    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::FetchWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method fetch has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("refspecs"));
      workerArguments.push(GetFromPersistent("opts"));
      workerArguments.push(GetFromPersistent("reflog_message"));
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
        v8::Local<v8::Object> err = Nan::Error("Method fetch has thrown an error.")->ToObject();
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
NAN_METHOD(GitRemote::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

git_remote_free(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
  
/*
     * @param Array callback
   */
NAN_METHOD(GitRemote::GetFetchRefspecs) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetFetchRefspecsBaton* baton = new GetFetchRefspecsBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->array = (git_strarray *)malloc(sizeof(git_strarray ));
  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  GetFetchRefspecsWorker *worker = new GetFetchRefspecsWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::GetFetchRefspecsWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->array
        ,baton->remote
);

  int result = git_remote_get_fetch_refspecs(
baton->array,baton->remote    );

  }
}

void GitRemote::GetFetchRefspecsWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
    v8::Local<Array> tmpArray = Nan::New<Array>(baton->array->count);
    for (unsigned int i = 0; i < baton->array->count; i++) {
      Nan::Set(tmpArray, Nan::New<Number>(i), Nan::New<String>(baton->array->strings[i]).ToLocalChecked());
    }
 
  to = tmpArray;
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
        err = Nan::Error("Method getFetchRefspecs has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method getFetchRefspecs has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        v8::Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

    free((void*)baton->array);
  }

  free((void *)baton->array);

  delete baton;
}

  
/*
     * @param Array callback
   */
NAN_METHOD(GitRemote::GetPushRefspecs) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetPushRefspecsBaton* baton = new GetPushRefspecsBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->array = (git_strarray *)malloc(sizeof(git_strarray ));
  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  GetPushRefspecsWorker *worker = new GetPushRefspecsWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::GetPushRefspecsWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->array
        ,baton->remote
);

  int result = git_remote_get_push_refspecs(
baton->array,baton->remote    );

  }
}

void GitRemote::GetPushRefspecsWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
    v8::Local<Array> tmpArray = Nan::New<Array>(baton->array->count);
    for (unsigned int i = 0; i < baton->array->count; i++) {
      Nan::Set(tmpArray, Nan::New<Number>(i), Nan::New<String>(baton->array->strings[i]).ToLocalChecked());
    }
 
  to = tmpArray;
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
        err = Nan::Error("Method getPushRefspecs has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method getPushRefspecs has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        v8::Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

    free((void*)baton->array);
  }

  free((void *)baton->array);

  delete baton;
}

   
/*
   * @param Number n
     * @return Refspec  result    */
NAN_METHOD(GitRemote::GetRefspec) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

// start convert_from_v8 block
  size_t from_n;
  from_n = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    const git_refspec * result = git_remote_get_refspec(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
,  from_n
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRefspec result
       to = GitRefspec::New(result, false , info.This() );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param RemoteCallbacks opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitRemote::InitCallbacks) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("RemoteCallbacks opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_remote_callbacks * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_opts
);

    int result = git_remote_init_callbacks(
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
   
/*
 * @param String remote_name
     * @return Number  result    */
NAN_METHOD(GitRemote::IsValidName) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String remote_name is required.");
  }

// start convert_from_v8 block
  const char * from_remote_name = NULL;

  String::Utf8Value remote_name(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote_name = (const char *) malloc(remote_name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote_name, *remote_name, remote_name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote_name) + remote_name.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_remote_name
);

    int result = git_remote_is_valid_name(
  from_remote_name
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Repository repo
    * @param Array callback
   */
NAN_METHOD(GitRemote::List) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ListBaton* baton = new ListBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_strarray *)malloc(sizeof(git_strarray ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  ListWorker *worker = new ListWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::ListWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->repo
);

  int result = git_remote_list(
baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::ListWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
    v8::Local<Array> tmpArray = Nan::New<Array>(baton->out->count);
    for (unsigned int i = 0; i < baton->out->count; i++) {
      Nan::Set(tmpArray, Nan::New<Number>(i), Nan::New<String>(baton->out->strings[i]).ToLocalChecked());
    }
 
  to = tmpArray;
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
        err = Nan::Error("Method list has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
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
        v8::Local<v8::Object> err = Nan::Error("Method list has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        v8::Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

    free((void*)baton->out);
  }

  free((void *)baton->out);

  delete baton;
}

  
/*
  * @param Repository repo
   * @param String name
    * @param Remote callback
   */
NAN_METHOD(GitRemote::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupBaton* baton = new LookupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name = NULL;

  String::Utf8Value name(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, *name, name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::LookupWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->name
);

  int result = git_remote_lookup(
&baton->out,baton->repo,baton->name    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRemote baton->out
       to = GitRemote::New(baton->out, true  );
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
        err = Nan::Error("Method lookup has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("name"));
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
        v8::Local<v8::Object> err = Nan::Error("Method lookup has thrown an error.")->ToObject();
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
     * @return String  result    */
NAN_METHOD(GitRemote::Name) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    const char * result = git_remote_name(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Repository  result    */
NAN_METHOD(GitRemote::Owner) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    git_repository * result = git_remote_owner(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRepository result
       to = GitRepository::New(result, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param RemoteCallbacks callbacks
     * @return Number  result    */
NAN_METHOD(GitRemote::Prune) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("RemoteCallbacks callbacks is required.");
  }

// start convert_from_v8 block
  const git_remote_callbacks * from_callbacks = NULL;
from_callbacks = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
        ,    from_callbacks
);

    int result = git_remote_prune(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
,  from_callbacks
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRemote::PruneRefs) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    int result = git_remote_prune_refs(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
   * @param Strarray refspecs
   * @param PushOptions opts
     */
NAN_METHOD(GitRemote::Push) {

  if (info.Length() == 0 || !(Nan::To<bool>(info[0]).FromJust())) {
    return Nan::ThrowError("Array, String Object, or string refspecs is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  PushBaton* baton = new PushBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_refspecs = NULL;

  from_refspecs = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->refspecs = from_refspecs;
// start convert_from_v8 block
  const git_push_options * from_opts = NULL;
    if (info[1]->IsObject()) {
from_opts = Nan::ObjectWrap::Unwrap<GitPushOptions>(info[1]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  PushWorker *worker = new PushWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("refspecs", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRemote::PushWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->remote
        ,baton->refspecs
        ,baton->opts
);

  int result = git_remote_push(
baton->remote,baton->refspecs,baton->opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRemote::PushWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> result = Nan::Undefined();
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
        err = Nan::Error("Method push has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("refspecs"));
      workerArguments.push(GetFromPersistent("opts"));
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
        v8::Local<v8::Object> err = Nan::Error("Method push has thrown an error.")->ToObject();
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
     * @return String  result    */
NAN_METHOD(GitRemote::Pushurl) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    const char * result = git_remote_pushurl(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRemote::RefspecCount) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    size_t result = git_remote_refspec_count(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Repository repo
   * @param String remote
   * @param Number value
     * @return Number  result    */
NAN_METHOD(GitRemote::SetAutotag) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String remote is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number value is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_remote = NULL;

  String::Utf8Value remote(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote = (const char *) malloc(remote.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote, *remote, remote.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote) + remote.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  git_remote_autotag_option_t from_value;
  from_value = (git_remote_autotag_option_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
        ,    from_remote
);

    int result = git_remote_set_autotag(
  from_repo
,  from_remote
,  from_value
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Repository repo
   * @param String remote
   * @param String url
     * @return Number  result    */
NAN_METHOD(GitRemote::SetPushurl) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String remote is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_remote = NULL;

  String::Utf8Value remote(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote = (const char *) malloc(remote.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote, *remote, remote.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote) + remote.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_url = NULL;

  String::Utf8Value url(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_url = (const char *) malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_url, *url, url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
        ,    from_remote
        ,    from_url
);

    int result = git_remote_set_pushurl(
  from_repo
,  from_remote
,  from_url
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Repository repo
   * @param String remote
   * @param String url
     * @return Number  result    */
NAN_METHOD(GitRemote::SetUrl) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String remote is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_remote = NULL;

  String::Utf8Value remote(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote = (const char *) malloc(remote.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote, *remote, remote.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote) + remote.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_url = NULL;

  String::Utf8Value url(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_url = (const char *) malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_url, *url, url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
        ,    from_remote
        ,    from_url
);

    int result = git_remote_set_url(
  from_repo
,  from_remote
,  from_url
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return TransferProgress  result    */
NAN_METHOD(GitRemote::Stats) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    const git_transfer_progress * result = git_remote_stats(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitTransferProgress result
       to = GitTransferProgress::New(result, false , info.This() );
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
NAN_METHOD(GitRemote::Stop) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

git_remote_stop(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
   * @param RemoteCallbacks callbacks
   * @param Number update_fetchhead
   * @param Number download_tags
   * @param String reflog_message
     * @return Number  result    */
NAN_METHOD(GitRemote::UpdateTips) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("RemoteCallbacks callbacks is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number update_fetchhead is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number download_tags is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String reflog_message is required.");
  }

// start convert_from_v8 block
  const git_remote_callbacks * from_callbacks = NULL;
from_callbacks = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_update_fetchhead;
  from_update_fetchhead = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  git_remote_autotag_option_t from_download_tags;
  from_download_tags = (git_remote_autotag_option_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_reflog_message = NULL;

  String::Utf8Value reflog_message(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_reflog_message = (const char *) malloc(reflog_message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_reflog_message, *reflog_message, reflog_message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_reflog_message) + reflog_message.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
        ,    from_callbacks
        ,    from_reflog_message
);

    int result = git_remote_update_tips(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
,  from_callbacks
,  from_update_fetchhead
,  from_download_tags
,  from_reflog_message
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param Strarray refspecs
   * @param PushOptions opts
     * @return Number  result    */
NAN_METHOD(GitRemote::Upload) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !(Nan::To<bool>(info[0]).FromJust())) {
    return Nan::ThrowError("Array, String Object, or string refspecs is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("PushOptions opts is required.");
  }

// start convert_from_v8 block
  const git_strarray * from_refspecs = NULL;

  from_refspecs = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_push_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitPushOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
        ,    from_refspecs
        ,    from_opts
);

    int result = git_remote_upload(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
,  from_refspecs
,  from_opts
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRemote::Url) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
);

    const char * result = git_remote_url(
  Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
        NAN_METHOD(GitRemote::ReferenceList)
{
  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ReferenceListBaton* baton = new ReferenceListBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = new std::vector<git_remote_head*>;
  baton->remote = Nan::ObjectWrap::Unwrap<GitRemote>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  ReferenceListWorker *worker = new ReferenceListWorker(baton, callback);
  worker->SaveToPersistent("remote", info.This());
  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRemote::ReferenceListWorker::Execute()
{
  giterr_clear();

  {
    LockMaster lockMaster(
      /*asyncAction: */true,
      baton->remote
    );

    const git_remote_head **remote_heads;
    size_t num_remote_heads;
    baton->error_code = git_remote_ls(
      &remote_heads,
      &num_remote_heads,
      baton->remote
    );

    if (baton->error_code != GIT_OK) {
      baton->error = git_error_dup(giterr_last());
      delete baton->out;
      baton->out = NULL;
      return;
    }

    baton->out->reserve(num_remote_heads);

    for (size_t head_index = 0; head_index < num_remote_heads; ++head_index) {
      git_remote_head *remote_head = git_remote_head_dup(remote_heads[head_index]);
      baton->out->push_back(remote_head);
    }
  }
}

void GitRemote::ReferenceListWorker::HandleOKCallback()
{
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Local<Array> result = Nan::New<Array>(size);
    for (unsigned int i = 0; i < size; i++) {
      Nan::Set(result, Nan::New<Number>(i), GitRemoteHead::New(baton->out->at(i), true));
    }

    delete baton->out;

    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  }
  else if (baton->error)
  {
    Local<v8::Value> argv[1] = {
      Nan::Error(baton->error->message)
    };
    callback->Call(1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Local<v8::Object> err = Nan::Error("Reference List has thrown an error.")->ToObject();
    err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
    Local<v8::Value> argv[1] = {
      err
    };
    callback->Call(1, argv);
  }
  else
  {
    callback->Call(0, NULL);
  }
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRemoteTraits>;
 