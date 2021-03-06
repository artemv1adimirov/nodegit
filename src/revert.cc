// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/revert.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/repository.h"
  #include "../include/commit.h"
  #include "../include/revert_options.h"
  #include "../include/index.h"
  #include "../include/merge_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitRevert::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "revert", Revert);
         Nan::SetMethod(object, "commit", Commit);
  
    Nan::Set(target, Nan::New<String>("Revert").ToLocalChecked(), object);
  }

 
/*
 * @param Repository repo
   * @param Commit commit
   * @param RevertOptions given_opts
     */
NAN_METHOD(GitRevert::Revert) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Commit commit is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RevertBaton* baton = new RevertBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_commit * from_commit = NULL;
from_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->commit = from_commit;
// start convert_from_v8 block
  const git_revert_options * from_given_opts = NULL;
    if (info[2]->IsObject()) {
from_given_opts = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info[2]->ToObject())->GetValue();
  }
  else {
    from_given_opts = 0;
  }
// end convert_from_v8 block
  baton->given_opts = from_given_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  RevertWorker *worker = new RevertWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("commit", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("given_opts", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRevert::RevertWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->commit
        ,baton->given_opts
);

  int result = git_revert(
baton->repo,baton->commit,baton->given_opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRevert::RevertWorker::HandleOKCallback() {
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
        err = Nan::Error("Method revert has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("commit"));
      workerArguments.push(GetFromPersistent("given_opts"));
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
        v8::Local<v8::Object> err = Nan::Error("Method revert has thrown an error.")->ToObject();
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
   * @param Commit revert_commit
   * @param Commit our_commit
   * @param Number mainline
   * @param MergeOptions merge_options
    * @param Index callback
   */
NAN_METHOD(GitRevert::Commit) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Commit revert_commit is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Commit our_commit is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number mainline is required.");
  }

  if (info.Length() == 5 || !info[5]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CommitBaton* baton = new CommitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_commit * from_revert_commit = NULL;
from_revert_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->revert_commit = from_revert_commit;
// start convert_from_v8 block
  git_commit * from_our_commit = NULL;
from_our_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->our_commit = from_our_commit;
// start convert_from_v8 block
  unsigned int from_mainline;
  from_mainline = (unsigned int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
  baton->mainline = from_mainline;
// start convert_from_v8 block
  const git_merge_options * from_merge_options = NULL;
    if (info[4]->IsObject()) {
from_merge_options = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info[4]->ToObject())->GetValue();
  }
  else {
    from_merge_options = 0;
  }
// end convert_from_v8 block
  baton->merge_options = from_merge_options;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[5]));
  CommitWorker *worker = new CommitWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("revert_commit", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("our_commit", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("mainline", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("merge_options", info[4]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRevert::CommitWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->revert_commit
        ,baton->our_commit
        ,baton->merge_options
);

  int result = git_revert_commit(
&baton->out,baton->repo,baton->revert_commit,baton->our_commit,baton->mainline,baton->merge_options    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRevert::CommitWorker::HandleOKCallback() {
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
        err = Nan::Error("Method commit has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("revert_commit"));
      workerArguments.push(GetFromPersistent("our_commit"));
      workerArguments.push(GetFromPersistent("mainline"));
      workerArguments.push(GetFromPersistent("merge_options"));
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
        v8::Local<v8::Object> err = Nan::Error("Method commit has thrown an error.")->ToObject();
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

     