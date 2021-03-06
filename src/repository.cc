// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/repository.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "git2/sys/repository.h"
  #include "../include/config.h"
  #include "../include/buf.h"
  #include "../include/oid.h"
  #include "../include/reference.h"
  #include "../include/index.h"
  #include "../include/repository_init_options.h"
  #include "../include/odb.h"
  #include "../include/refdb.h"
  #include "../include/annotated_commit.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRepository::~GitRepository() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                                     }

  void GitRepository::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Repository").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "cleanup", Cleanup);
            Nan::SetPrototypeMethod(tpl, "config", Config);
            Nan::SetPrototypeMethod(tpl, "configSnapshot", ConfigSnapshot);
            Nan::SetPrototypeMethod(tpl, "detachHead", DetachHead);
             Nan::SetMethod(tpl, "discover", Discover);
            Nan::SetPrototypeMethod(tpl, "fetchheadForeach", FetchheadForeach);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "getNamespace", GetNamespace);
            Nan::SetPrototypeMethod(tpl, "head", Head);
            Nan::SetPrototypeMethod(tpl, "headDetached", HeadDetached);
            Nan::SetPrototypeMethod(tpl, "headUnborn", HeadUnborn);
            Nan::SetPrototypeMethod(tpl, "index", Index);
             Nan::SetMethod(tpl, "init", Init);
             Nan::SetMethod(tpl, "initExt", InitExt);
            Nan::SetPrototypeMethod(tpl, "isBare", IsBare);
            Nan::SetPrototypeMethod(tpl, "isEmpty", IsEmpty);
            Nan::SetPrototypeMethod(tpl, "isShallow", IsShallow);
            Nan::SetPrototypeMethod(tpl, "mergeheadForeach", MergeheadForeach);
            Nan::SetPrototypeMethod(tpl, "messageRemove", MessageRemove);
            Nan::SetPrototypeMethod(tpl, "odb", Odb);
             Nan::SetMethod(tpl, "open", Open);
             Nan::SetMethod(tpl, "openBare", OpenBare);
             Nan::SetMethod(tpl, "openExt", OpenExt);
            Nan::SetPrototypeMethod(tpl, "path", Path);
            Nan::SetPrototypeMethod(tpl, "refdb", Refdb);
            Nan::SetPrototypeMethod(tpl, "setHead", SetHead);
            Nan::SetPrototypeMethod(tpl, "setHeadDetached", SetHeadDetached);
            Nan::SetPrototypeMethod(tpl, "setHeadDetachedFromAnnotated", SetHeadDetachedFromAnnotated);
            Nan::SetPrototypeMethod(tpl, "setIdent", SetIdent);
            Nan::SetPrototypeMethod(tpl, "setIndex", SetIndex);
            Nan::SetPrototypeMethod(tpl, "setNamespace", SetNamespace);
            Nan::SetPrototypeMethod(tpl, "setWorkdir", SetWorkdir);
            Nan::SetPrototypeMethod(tpl, "state", State);
            Nan::SetPrototypeMethod(tpl, "stateCleanup", StateCleanup);
            Nan::SetPrototypeMethod(tpl, "submoduleCacheAll", SubmoduleCacheAll);
            Nan::SetPrototypeMethod(tpl, "submoduleCacheClear", SubmoduleCacheClear);
            Nan::SetPrototypeMethod(tpl, "workdir", Workdir);
             Nan::SetMethod(tpl, "wrapOdb", WrapOdb);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Repository").ToLocalChecked(), _constructor_template);
  }

  
/*
     */
NAN_METHOD(GitRepository::Cleanup) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

git_repository__cleanup(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
  
/*
     * @param Config callback
   */
NAN_METHOD(GitRepository::Config) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConfigBaton* baton = new ConfigBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  ConfigWorker *worker = new ConfigWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::ConfigWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_config(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::ConfigWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New(baton->out, false  );
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
        err = Nan::Error("Method config has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method config has thrown an error.")->ToObject();
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
     * @param Config callback
   */
NAN_METHOD(GitRepository::ConfigSnapshot) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConfigSnapshotBaton* baton = new ConfigSnapshotBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  ConfigSnapshotWorker *worker = new ConfigSnapshotWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::ConfigSnapshotWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_config_snapshot(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::ConfigSnapshotWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New(baton->out, false  );
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
        err = Nan::Error("Method configSnapshot has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method configSnapshot has thrown an error.")->ToObject();
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
NAN_METHOD(GitRepository::DetachHead) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_detach_head(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param String start_path
   * @param Number across_fs
   * @param String ceiling_dirs
    * @param Buf callback
   */
NAN_METHOD(GitRepository::Discover) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String start_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number across_fs is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String ceiling_dirs is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DiscoverBaton* baton = new DiscoverBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->asize = 0;
// start convert_from_v8 block
  const char * from_start_path = NULL;

  String::Utf8Value start_path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_start_path = (const char *) malloc(start_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_start_path, *start_path, start_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_start_path) + start_path.length()), 0, 1);
// end convert_from_v8 block
  baton->start_path = from_start_path;
// start convert_from_v8 block
  int from_across_fs;
  from_across_fs = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->across_fs = from_across_fs;
// start convert_from_v8 block
  const char * from_ceiling_dirs = NULL;

  String::Utf8Value ceiling_dirs(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_ceiling_dirs = (const char *) malloc(ceiling_dirs.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_ceiling_dirs, *ceiling_dirs, ceiling_dirs.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_ceiling_dirs) + ceiling_dirs.length()), 0, 1);
// end convert_from_v8 block
  baton->ceiling_dirs = from_ceiling_dirs;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  DiscoverWorker *worker = new DiscoverWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("start_path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("across_fs", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("ceiling_dirs", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::DiscoverWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->start_path
        ,baton->ceiling_dirs
);

  int result = git_repository_discover(
baton->out,baton->start_path,baton->across_fs,baton->ceiling_dirs    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::DiscoverWorker::HandleOKCallback() {
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
        err = Nan::Error("Method discover has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("start_path"));
      workerArguments.push(GetFromPersistent("across_fs"));
      workerArguments.push(GetFromPersistent("ceiling_dirs"));
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
        v8::Local<v8::Object> err = Nan::Error("Method discover has thrown an error.")->ToObject();
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
   * @param RepositoryFetchheadForeachCb callback
   * @param Void payload
     */
NAN_METHOD(GitRepository::FetchheadForeach) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("RepositoryFetchheadForeachCb callback is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FetchheadForeachBaton* baton = new FetchheadForeachBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  FetchheadForeach_globalPayload* globalPayload = new FetchheadForeach_globalPayload;
  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();
  if (!info[0]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = FetchheadForeach_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[0].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  FetchheadForeachWorker *worker = new FetchheadForeachWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("payload", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::FetchheadForeachWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->payload
);

  int result = git_repository_fetchhead_foreach(
baton->repo,baton->callback,baton->payload    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::FetchheadForeachWorker::HandleOKCallback() {
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
        err = Nan::Error("Method fetchheadForeach has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method fetchheadForeach has thrown an error.")->ToObject();
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

  delete (FetchheadForeach_globalPayload*)baton->payload;

  delete baton;
}


int GitRepository::FetchheadForeach_callback_cppCallback (
    const char * refname,     const char * remote_url,     const git_oid * oid,     unsigned int is_merge,     void * payload  ) {
  FetchheadForeach_CallbackBaton baton(0);

    baton.refname = refname;
    baton.remote_url = remote_url;
    baton.oid = oid;
    baton.is_merge = is_merge;
    baton.payload = payload;
 
  return baton.ExecuteAsync(FetchheadForeach_callback_async);
}

void GitRepository::FetchheadForeach_callback_async(void *untypedBaton) {
  Nan::HandleScope scope;

  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(untypedBaton);

      Nan::Callback* callback = ((FetchheadForeach_globalPayload*)baton->payload)->callback;
   
  v8::Local<Value> argv[5] = {
          Nan::New(baton->refname).ToLocalChecked(),
            Nan::New(baton->remote_url).ToLocalChecked(),
            GitOid::New(baton->oid, false),
             Nan::New(baton->is_merge),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  v8::Local<v8::Value> result = callback->Call(5, argv);

  if(PromiseCompletion::ForwardIfPromise(result, baton, FetchheadForeach_callback_promiseCompleted)) {
    return;
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = 1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitRepository::FetchheadForeach_callback_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
  Nan::HandleScope scope;

  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = 1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitRepository* instance = static_cast<GitRepository*>(baton->    payload  );
    v8::Local<v8::Object> parent = instance->handle();
    SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

    baton->result = 1;
  }
  baton->Done();
}
   
/*
     */
NAN_METHOD(GitRepository::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

git_repository_free(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRepository::GetNamespace) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    const char * result = git_repository_get_namespace(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
     * @param Reference callback
   */
NAN_METHOD(GitRepository::Head) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  HeadBaton* baton = new HeadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  HeadWorker *worker = new HeadWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::HeadWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_head(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::HeadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefs baton->out
       to = GitRefs::New(baton->out, true  );
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
        err = Nan::Error("Method head has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method head has thrown an error.")->ToObject();
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
NAN_METHOD(GitRepository::HeadDetached) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_head_detached(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::HeadUnborn) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_head_unborn(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
     * @param Index callback
   */
NAN_METHOD(GitRepository::Index) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  IndexBaton* baton = new IndexBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  IndexWorker *worker = new IndexWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::IndexWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_index(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::IndexWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitIndex baton->out
       to = GitIndex::New(baton->out, false  );
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
        err = Nan::Error("Method index has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method index has thrown an error.")->ToObject();
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
  * @param String path
   * @param Number is_bare
    * @param Repository callback
   */
NAN_METHOD(GitRepository::Init) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number is_bare is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InitBaton* baton = new InitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path = NULL;

  String::Utf8Value path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, *path, path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  unsigned int from_is_bare;
  from_is_bare = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->is_bare = from_is_bare;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  InitWorker *worker = new InitWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("is_bare", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::InitWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->path
);

  int result = git_repository_init(
&baton->out,baton->path,baton->is_bare    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::InitWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method init has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("is_bare"));
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
        v8::Local<v8::Object> err = Nan::Error("Method init has thrown an error.")->ToObject();
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
  * @param String repo_path
   * @param RepositoryInitOptions opts
    * @param Repository callback
   */
NAN_METHOD(GitRepository::InitExt) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String repo_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("RepositoryInitOptions opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InitExtBaton* baton = new InitExtBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_repo_path = NULL;

  String::Utf8Value repo_path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_repo_path = (const char *) malloc(repo_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_repo_path, *repo_path, repo_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_repo_path) + repo_path.length()), 0, 1);
// end convert_from_v8 block
  baton->repo_path = from_repo_path;
// start convert_from_v8 block
  git_repository_init_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitRepositoryInitOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  InitExtWorker *worker = new InitExtWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo_path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::InitExtWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo_path
        ,baton->opts
);

  int result = git_repository_init_ext(
&baton->out,baton->repo_path,baton->opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::InitExtWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method initExt has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("repo_path"));
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
        v8::Local<v8::Object> err = Nan::Error("Method initExt has thrown an error.")->ToObject();
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
NAN_METHOD(GitRepository::IsBare) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_is_bare(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::IsEmpty) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_is_empty(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::IsShallow) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_is_shallow(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
   * @param RepositoryMergeheadForeachCb callback
   * @param Void payload
     */
NAN_METHOD(GitRepository::MergeheadForeach) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("RepositoryMergeheadForeachCb callback is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  MergeheadForeachBaton* baton = new MergeheadForeachBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  MergeheadForeach_globalPayload* globalPayload = new MergeheadForeach_globalPayload;
  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();
  if (!info[0]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = MergeheadForeach_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[0].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  MergeheadForeachWorker *worker = new MergeheadForeachWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("payload", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::MergeheadForeachWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->payload
);

  int result = git_repository_mergehead_foreach(
baton->repo,baton->callback,baton->payload    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::MergeheadForeachWorker::HandleOKCallback() {
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
        err = Nan::Error("Method mergeheadForeach has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method mergeheadForeach has thrown an error.")->ToObject();
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

  delete (MergeheadForeach_globalPayload*)baton->payload;

  delete baton;
}


int GitRepository::MergeheadForeach_callback_cppCallback (
    const git_oid * oid,     void * payload  ) {
  MergeheadForeach_CallbackBaton baton(0);

    baton.oid = oid;
    baton.payload = payload;
 
  return baton.ExecuteAsync(MergeheadForeach_callback_async);
}

void GitRepository::MergeheadForeach_callback_async(void *untypedBaton) {
  Nan::HandleScope scope;

  MergeheadForeach_CallbackBaton* baton = static_cast<MergeheadForeach_CallbackBaton*>(untypedBaton);

   Nan::Callback* callback = ((MergeheadForeach_globalPayload*)baton->payload)->callback;
   
  v8::Local<Value> argv[2] = {
          GitOid::New(baton->oid, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  v8::Local<v8::Value> result = callback->Call(2, argv);

  if(PromiseCompletion::ForwardIfPromise(result, baton, MergeheadForeach_callback_promiseCompleted)) {
    return;
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = 1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitRepository::MergeheadForeach_callback_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
  Nan::HandleScope scope;

  MergeheadForeach_CallbackBaton* baton = static_cast<MergeheadForeach_CallbackBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = 1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitRepository* instance = static_cast<GitRepository*>(baton-> payload  );
    v8::Local<v8::Object> parent = instance->handle();
    SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

    baton->result = 1;
  }
  baton->Done();
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::MessageRemove) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_message_remove(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
     * @param Odb callback
   */
NAN_METHOD(GitRepository::Odb) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OdbBaton* baton = new OdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  OdbWorker *worker = new OdbWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::OdbWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_odb(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::OdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOdb baton->out
       to = GitOdb::New(baton->out, false  );
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
        err = Nan::Error("Method odb has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method odb has thrown an error.")->ToObject();
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
  * @param String path
    * @param Repository callback
   */
NAN_METHOD(GitRepository::Open) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBaton* baton = new OpenBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path = NULL;

  String::Utf8Value path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, *path, path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
  baton->path = from_path;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  OpenWorker *worker = new OpenWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::OpenWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->path
);

  int result = git_repository_open(
&baton->out,baton->path    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::OpenWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method open has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("path"));
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
        v8::Local<v8::Object> err = Nan::Error("Method open has thrown an error.")->ToObject();
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
  * @param String bare_path
    * @param Repository callback
   */
NAN_METHOD(GitRepository::OpenBare) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String bare_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBareBaton* baton = new OpenBareBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_bare_path = NULL;

  String::Utf8Value bare_path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_bare_path = (const char *) malloc(bare_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_bare_path, *bare_path, bare_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_bare_path) + bare_path.length()), 0, 1);
// end convert_from_v8 block
  baton->bare_path = from_bare_path;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  OpenBareWorker *worker = new OpenBareWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("bare_path", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::OpenBareWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->bare_path
);

  int result = git_repository_open_bare(
&baton->out,baton->bare_path    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::OpenBareWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method openBare has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("bare_path"));
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
        v8::Local<v8::Object> err = Nan::Error("Method openBare has thrown an error.")->ToObject();
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
  * @param String path
   * @param Number flags
   * @param String ceiling_dirs
    * @param Repository callback
   */
NAN_METHOD(GitRepository::OpenExt) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String ceiling_dirs is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenExtBaton* baton = new OpenExtBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path = NULL;

  String::Utf8Value path(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, *path, path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  unsigned int from_flags;
  from_flags = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
// start convert_from_v8 block
  const char * from_ceiling_dirs = NULL;

  String::Utf8Value ceiling_dirs(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_ceiling_dirs = (const char *) malloc(ceiling_dirs.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_ceiling_dirs, *ceiling_dirs, ceiling_dirs.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_ceiling_dirs) + ceiling_dirs.length()), 0, 1);
// end convert_from_v8 block
  baton->ceiling_dirs = from_ceiling_dirs;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  OpenExtWorker *worker = new OpenExtWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("ceiling_dirs", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::OpenExtWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->path
        ,baton->ceiling_dirs
);

  int result = git_repository_open_ext(
&baton->out,baton->path,baton->flags,baton->ceiling_dirs    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::OpenExtWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method openExt has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("flags"));
      workerArguments.push(GetFromPersistent("ceiling_dirs"));
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
        v8::Local<v8::Object> err = Nan::Error("Method openExt has thrown an error.")->ToObject();
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
NAN_METHOD(GitRepository::Path) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    const char * result = git_repository_path(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
     * @param Refdb callback
   */
NAN_METHOD(GitRepository::Refdb) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RefdbBaton* baton = new RefdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  RefdbWorker *worker = new RefdbWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::RefdbWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
);

  int result = git_repository_refdb(
&baton->out,baton->repo    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::RefdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefdb baton->out
       to = GitRefdb::New(baton->out, false  );
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
        err = Nan::Error("Method refdb has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method refdb has thrown an error.")->ToObject();
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
   * @param String refname
     */
NAN_METHOD(GitRepository::SetHead) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SetHeadBaton* baton = new SetHeadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_refname = NULL;

  String::Utf8Value refname(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refname = (const char *) malloc(refname.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refname, *refname, refname.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refname) + refname.length()), 0, 1);
// end convert_from_v8 block
  baton->refname = from_refname;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  SetHeadWorker *worker = new SetHeadWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("refname", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::SetHeadWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->refname
);

  int result = git_repository_set_head(
baton->repo,baton->refname    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::SetHeadWorker::HandleOKCallback() {
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
        err = Nan::Error("Method setHead has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("refname"));
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
        v8::Local<v8::Object> err = Nan::Error("Method setHead has thrown an error.")->ToObject();
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
   * @param Oid commitish
     * @return Number  result    */
NAN_METHOD(GitRepository::SetHeadDetached) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid commitish is required.");
  }
// start convert_from_v8 block
  const git_oid * from_commitish = NULL;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_commitish = oidOut;
  }
  else {
from_commitish = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_commitish
);

    int result = git_repository_set_head_detached(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_commitish
    );

     if (info[0]->IsString()) {
      free((void *)from_commitish);
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param AnnotatedCommit commitish
     * @return Number  result    */
NAN_METHOD(GitRepository::SetHeadDetachedFromAnnotated) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("AnnotatedCommit commitish is required.");
  }

// start convert_from_v8 block
  const git_annotated_commit * from_commitish = NULL;
from_commitish = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_commitish
);

    int result = git_repository_set_head_detached_from_annotated(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_commitish
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String name
   * @param String email
     * @return Number  result    */
NAN_METHOD(GitRepository::SetIdent) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

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
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_name
        ,    from_email
);

    int result = git_repository_set_ident(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_name
,  from_email
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param Index index
     */
NAN_METHOD(GitRepository::SetIndex) {
  Nan::EscapableHandleScope scope;

// start convert_from_v8 block
  git_index * from_index = NULL;
    if (info[0]->IsObject()) {
from_index = Nan::ObjectWrap::Unwrap<GitIndex>(info[0]->ToObject())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_index
);

git_repository_set_index(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_index
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
   * @param String nmspace
     * @return Number  result    */
NAN_METHOD(GitRepository::SetNamespace) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String nmspace is required.");
  }

// start convert_from_v8 block
  const char * from_nmspace = NULL;

  String::Utf8Value nmspace(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_nmspace = (const char *) malloc(nmspace.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_nmspace, *nmspace, nmspace.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_nmspace) + nmspace.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_nmspace
);

    int result = git_repository_set_namespace(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_nmspace
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String workdir
   * @param Number update_gitlink
     * @return Number  result    */
NAN_METHOD(GitRepository::SetWorkdir) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String workdir is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number update_gitlink is required.");
  }

// start convert_from_v8 block
  const char * from_workdir = NULL;

  String::Utf8Value workdir(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_workdir = (const char *) malloc(workdir.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_workdir, *workdir, workdir.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_workdir) + workdir.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_update_gitlink;
  from_update_gitlink = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
        ,    from_workdir
);

    int result = git_repository_set_workdir(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,  from_workdir
,  from_update_gitlink
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
NAN_METHOD(GitRepository::State) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_state(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::StateCleanup) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_state_cleanup(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::SubmoduleCacheAll) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_submodule_cache_all(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::SubmoduleCacheClear) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    int result = git_repository_submodule_cache_clear(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
NAN_METHOD(GitRepository::Workdir) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
);

    const char * result = git_repository_workdir(
  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
  * @param Odb odb
    * @param Repository callback
   */
NAN_METHOD(GitRepository::WrapOdb) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Odb odb is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  WrapOdbBaton* baton = new WrapOdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_odb * from_odb = NULL;
from_odb = Nan::ObjectWrap::Unwrap<GitOdb>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->odb = from_odb;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  WrapOdbWorker *worker = new WrapOdbWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("odb", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRepository::WrapOdbWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->odb
);

  int result = git_repository_wrap_odb(
&baton->out,baton->odb    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRepository::WrapOdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New(baton->out, false  );
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
        err = Nan::Error("Method wrapOdb has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("odb"));
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
        v8::Local<v8::Object> err = Nan::Error("Method wrapOdb has thrown an error.")->ToObject();
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

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRepositoryTraits>;
 