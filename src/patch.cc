// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/patch.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/convenient_patch.h"
  #include "../include/blob.h"
  #include "../include/diff_options.h"
  #include "../include/diff.h"
  #include "../include/diff_delta.h"
  #include "../include/diff_hunk.h"
  #include "../include/diff_line.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitPatch::~GitPatch() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                               }

  void GitPatch::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Patch").ToLocalChecked());

           Nan::SetMethod(tpl, "fromBlobAndBuffer", FromBlobAndBuffer);
             Nan::SetMethod(tpl, "fromBlobs", FromBlobs);
             Nan::SetMethod(tpl, "fromDiff", FromDiff);
            Nan::SetPrototypeMethod(tpl, "getDelta", GetDelta);
            Nan::SetPrototypeMethod(tpl, "getHunk", GetHunk);
            Nan::SetPrototypeMethod(tpl, "getLineInHunk", GetLineInHunk);
            Nan::SetPrototypeMethod(tpl, "lineStats", LineStats);
            Nan::SetPrototypeMethod(tpl, "numHunks", NumHunks);
            Nan::SetPrototypeMethod(tpl, "numLinesInHunk", NumLinesInHunk);
            Nan::SetPrototypeMethod(tpl, "size", Size);
             Nan::SetMethod(tpl, "convenientFromDiff", ConvenientFromDiff);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Patch").ToLocalChecked(), _constructor_template);
  }

 
/*
  * @param Blob old_blob
   * @param String old_as_path
   * @param String buffer
   * @param Number buffer_len
   * @param String buffer_as_path
   * @param DiffOptions opts
    * @param Patch callback
   */
NAN_METHOD(GitPatch::FromBlobAndBuffer) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Blob old_blob is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String old_as_path is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String buffer is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number buffer_len is required.");
  }

  if (info.Length() == 4 || !info[4]->IsString()) {
    return Nan::ThrowError("String buffer_as_path is required.");
  }

  if (info.Length() == 5 || !info[5]->IsObject()) {
    return Nan::ThrowError("DiffOptions opts is required.");
  }

  if (info.Length() == 6 || !info[6]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FromBlobAndBufferBaton* baton = new FromBlobAndBufferBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const git_blob * from_old_blob = NULL;
from_old_blob = Nan::ObjectWrap::Unwrap<GitBlob>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->old_blob = from_old_blob;
// start convert_from_v8 block
  const char * from_old_as_path = NULL;

  String::Utf8Value old_as_path(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_old_as_path = (const char *) malloc(old_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_old_as_path, *old_as_path, old_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_old_as_path) + old_as_path.length()), 0, 1);
// end convert_from_v8 block
  baton->old_as_path = from_old_as_path;
// start convert_from_v8 block
  const char * from_buffer = NULL;

  String::Utf8Value buffer(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buffer = (const char *) malloc(buffer.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buffer, *buffer, buffer.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buffer) + buffer.length()), 0, 1);
// end convert_from_v8 block
  baton->buffer = from_buffer;
// start convert_from_v8 block
  size_t from_buffer_len;
  from_buffer_len = (size_t)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
  baton->buffer_len = from_buffer_len;
// start convert_from_v8 block
  const char * from_buffer_as_path = NULL;

  String::Utf8Value buffer_as_path(info[4]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buffer_as_path = (const char *) malloc(buffer_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buffer_as_path, *buffer_as_path, buffer_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buffer_as_path) + buffer_as_path.length()), 0, 1);
// end convert_from_v8 block
  baton->buffer_as_path = from_buffer_as_path;
// start convert_from_v8 block
  const git_diff_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[5]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[6]));
  FromBlobAndBufferWorker *worker = new FromBlobAndBufferWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("old_blob", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_as_path", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("buffer", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("buffer_len", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("buffer_as_path", info[4]->ToObject());
  if (!info[5]->IsUndefined() && !info[5]->IsNull())
    worker->SaveToPersistent("opts", info[5]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitPatch::FromBlobAndBufferWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->old_blob
        ,baton->old_as_path
        ,baton->buffer
        ,baton->buffer_as_path
        ,baton->opts
);

  int result = git_patch_from_blob_and_buffer(
&baton->out,baton->old_blob,baton->old_as_path,baton->buffer,baton->buffer_len,baton->buffer_as_path,baton->opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitPatch::FromBlobAndBufferWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPatch baton->out
       to = GitPatch::New(baton->out, false  );
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
        err = Nan::Error("Method fromBlobAndBuffer has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("old_blob"));
      workerArguments.push(GetFromPersistent("old_as_path"));
      workerArguments.push(GetFromPersistent("buffer"));
      workerArguments.push(GetFromPersistent("buffer_len"));
      workerArguments.push(GetFromPersistent("buffer_as_path"));
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
        v8::Local<v8::Object> err = Nan::Error("Method fromBlobAndBuffer has thrown an error.")->ToObject();
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
  * @param Blob old_blob
   * @param String old_as_path
   * @param Blob new_blob
   * @param String new_as_path
   * @param DiffOptions opts
    * @param Patch callback
   */
NAN_METHOD(GitPatch::FromBlobs) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Blob old_blob is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String old_as_path is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Blob new_blob is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String new_as_path is required.");
  }

  if (info.Length() == 4 || !info[4]->IsObject()) {
    return Nan::ThrowError("DiffOptions opts is required.");
  }

  if (info.Length() == 5 || !info[5]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FromBlobsBaton* baton = new FromBlobsBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const git_blob * from_old_blob = NULL;
from_old_blob = Nan::ObjectWrap::Unwrap<GitBlob>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->old_blob = from_old_blob;
// start convert_from_v8 block
  const char * from_old_as_path = NULL;

  String::Utf8Value old_as_path(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_old_as_path = (const char *) malloc(old_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_old_as_path, *old_as_path, old_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_old_as_path) + old_as_path.length()), 0, 1);
// end convert_from_v8 block
  baton->old_as_path = from_old_as_path;
// start convert_from_v8 block
  const git_blob * from_new_blob = NULL;
from_new_blob = Nan::ObjectWrap::Unwrap<GitBlob>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->new_blob = from_new_blob;
// start convert_from_v8 block
  const char * from_new_as_path = NULL;

  String::Utf8Value new_as_path(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_new_as_path = (const char *) malloc(new_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_new_as_path, *new_as_path, new_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_new_as_path) + new_as_path.length()), 0, 1);
// end convert_from_v8 block
  baton->new_as_path = from_new_as_path;
// start convert_from_v8 block
  const git_diff_options * from_opts = NULL;
from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[4]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[5]));
  FromBlobsWorker *worker = new FromBlobsWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("old_blob", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_as_path", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("new_blob", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("new_as_path", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("opts", info[4]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitPatch::FromBlobsWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->old_blob
        ,baton->old_as_path
        ,baton->new_blob
        ,baton->new_as_path
        ,baton->opts
);

  int result = git_patch_from_blobs(
&baton->out,baton->old_blob,baton->old_as_path,baton->new_blob,baton->new_as_path,baton->opts    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitPatch::FromBlobsWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPatch baton->out
       to = GitPatch::New(baton->out, false  );
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
        err = Nan::Error("Method fromBlobs has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("old_blob"));
      workerArguments.push(GetFromPersistent("old_as_path"));
      workerArguments.push(GetFromPersistent("new_blob"));
      workerArguments.push(GetFromPersistent("new_as_path"));
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
        v8::Local<v8::Object> err = Nan::Error("Method fromBlobs has thrown an error.")->ToObject();
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
  * @param Diff diff
   * @param Number idx
    * @param Patch callback
   */
NAN_METHOD(GitPatch::FromDiff) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Diff diff is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FromDiffBaton* baton = new FromDiffBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_diff * from_diff = NULL;
from_diff = Nan::ObjectWrap::Unwrap<GitDiff>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->diff = from_diff;
// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->idx = from_idx;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  FromDiffWorker *worker = new FromDiffWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("diff", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("idx", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitPatch::FromDiffWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->diff
);

  int result = git_patch_from_diff(
&baton->out,baton->diff,baton->idx    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitPatch::FromDiffWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitPatch baton->out
       to = GitPatch::New(baton->out, false  );
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
        err = Nan::Error("Method fromDiff has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("diff"));
      workerArguments.push(GetFromPersistent("idx"));
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
        v8::Local<v8::Object> err = Nan::Error("Method fromDiff has thrown an error.")->ToObject();
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
     * @return DiffDelta  result    */
NAN_METHOD(GitPatch::GetDelta) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
);

    const git_diff_delta * result = git_patch_get_delta(
  Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitDiffDelta result
       to = GitDiffDelta::New(result, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
     * @param Number hunk_idx
    * @param DiffHunk callback
  * @param Number callback
   */
NAN_METHOD(GitPatch::GetHunk) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number hunk_idx is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetHunkBaton* baton = new GetHunkBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->lines_in_hunk = (size_t *)malloc(sizeof(size_t ));
  baton->patch = Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue();
// start convert_from_v8 block
  size_t from_hunk_idx;
  from_hunk_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->hunk_idx = from_hunk_idx;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  GetHunkWorker *worker = new GetHunkWorker(baton, callback);
  worker->SaveToPersistent("patch", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("hunk_idx", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitPatch::GetHunkWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->lines_in_hunk
        ,baton->patch
);

  int result = git_patch_get_hunk(
&baton->out,baton->lines_in_hunk,baton->patch,baton->hunk_idx    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitPatch::GetHunkWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
    v8::Local<Object> result = Nan::New<Object>();
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitDiffHunk baton->out
       to = GitDiffHunk::New(baton->out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Nan::Set(result, Nan::New("hunk").ToLocalChecked(), to);
// start convert_to_v8 block
     to = Nan::New<Number>(* baton->lines_in_hunk);
  // end convert_to_v8 block
    Nan::Set(result, Nan::New("linesInHunk").ToLocalChecked(), to);
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
        err = Nan::Error("Method getHunk has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("hunk_idx"));
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
        v8::Local<v8::Object> err = Nan::Error("Method getHunk has thrown an error.")->ToObject();
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
    * @param Number hunk_idx
   * @param Number line_of_hunk
    * @param DiffLine callback
   */
NAN_METHOD(GitPatch::GetLineInHunk) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number hunk_idx is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number line_of_hunk is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetLineInHunkBaton* baton = new GetLineInHunkBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->patch = Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue();
// start convert_from_v8 block
  size_t from_hunk_idx;
  from_hunk_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->hunk_idx = from_hunk_idx;
// start convert_from_v8 block
  size_t from_line_of_hunk;
  from_line_of_hunk = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->line_of_hunk = from_line_of_hunk;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  GetLineInHunkWorker *worker = new GetLineInHunkWorker(baton, callback);
  worker->SaveToPersistent("patch", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("hunk_idx", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("line_of_hunk", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitPatch::GetLineInHunkWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->patch
);

  int result = git_patch_get_line_in_hunk(
&baton->out,baton->patch,baton->hunk_idx,baton->line_of_hunk    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitPatch::GetLineInHunkWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitDiffLine baton->out
       to = GitDiffLine::New(baton->out, false  );
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
        err = Nan::Error("Method getLineInHunk has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("hunk_idx"));
      workerArguments.push(GetFromPersistent("line_of_hunk"));
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
        v8::Local<v8::Object> err = Nan::Error("Method getLineInHunk has thrown an error.")->ToObject();
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
        * @return Number total_context    * @return Number total_additions    * @return Number total_deletions    */
NAN_METHOD(GitPatch::LineStats) {
  Nan::EscapableHandleScope scope;

  size_t total_context = 0;
  size_t total_additions = 0;
  size_t total_deletions = 0;
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
);

git_patch_line_stats(
&  total_context
,&  total_additions
,&  total_deletions
,  Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
    v8::Local<Object> toReturn = Nan::New<Object>();
// start convert_to_v8 block
     to = Nan::New<Number>( total_context);
  // end convert_to_v8 block
    Nan::Set(toReturn, Nan::New("total_context").ToLocalChecked(), to);
// start convert_to_v8 block
     to = Nan::New<Number>( total_additions);
  // end convert_to_v8 block
    Nan::Set(toReturn, Nan::New("total_additions").ToLocalChecked(), to);
// start convert_to_v8 block
     to = Nan::New<Number>( total_deletions);
  // end convert_to_v8 block
    Nan::Set(toReturn, Nan::New("total_deletions").ToLocalChecked(), to);
    return info.GetReturnValue().Set(scope.Escape(toReturn));
  }
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitPatch::NumHunks) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
);

    size_t result = git_patch_num_hunks(
  Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param Number hunk_idx
     * @return Number  result    */
NAN_METHOD(GitPatch::NumLinesInHunk) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number hunk_idx is required.");
  }

// start convert_from_v8 block
  size_t from_hunk_idx;
  from_hunk_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
);

    int result = git_patch_num_lines_in_hunk(
  Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
,  from_hunk_idx
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param Number include_context
   * @param Number include_hunk_headers
   * @param Number include_file_headers
     * @return Number  result    */
NAN_METHOD(GitPatch::Size) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number include_context is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number include_hunk_headers is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number include_file_headers is required.");
  }

// start convert_from_v8 block
  int from_include_context;
  from_include_context = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_include_hunk_headers;
  from_include_hunk_headers = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_include_file_headers;
  from_include_file_headers = (int)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
);

    size_t result = git_patch_size(
  Nan::ObjectWrap::Unwrap<GitPatch>(info.This())->GetValue()
,  from_include_context
,  from_include_hunk_headers
,  from_include_file_headers
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
        NAN_METHOD(GitPatch::ConvenientFromDiff) {
  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Diff diff is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConvenientFromDiffBaton *baton = new ConvenientFromDiffBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->diff = Nan::ObjectWrap::Unwrap<GitDiff>(info[0]->ToObject())->GetValue();
  baton->out = new std::vector<PatchData *>;
  baton->out->reserve(git_diff_num_deltas(baton->diff));

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  ConvenientFromDiffWorker *worker = new ConvenientFromDiffWorker(baton, callback);

  worker->SaveToPersistent("diff", info[0]);

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitPatch::ConvenientFromDiffWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(true, baton->diff);
    std::vector<git_patch *> patchesToBeFreed;

    for (int i = 0; i < git_diff_num_deltas(baton->diff); ++i) {
      git_patch *nextPatch;
      int result = git_patch_from_diff(&nextPatch, baton->diff, i);

      if (result) {
        while (!patchesToBeFreed.empty())
        {
          git_patch_free(patchesToBeFreed.back());
          patchesToBeFreed.pop_back();
        }

        while (!baton->out->empty()) {
          PatchDataFree(baton->out->back());
          baton->out->pop_back();
        }

        baton->error_code = result;

        if (giterr_last() != NULL) {
          baton->error = git_error_dup(giterr_last());
        }

        delete baton->out;
        baton->out = NULL;

        return;
      }

      if (nextPatch != NULL) {
        baton->out->push_back(createFromRaw(nextPatch));
        patchesToBeFreed.push_back(nextPatch);
      }
    }

    while (!patchesToBeFreed.empty())
    {
      git_patch_free(patchesToBeFreed.back());
      patchesToBeFreed.pop_back();
    }
  }
}

void GitPatch::ConvenientFromDiffWorker::HandleOKCallback() {
  if (baton->out != NULL) {
    unsigned int size = baton->out->size();
    Local<Array> result = Nan::New<Array>(size);

    for (unsigned int i = 0; i < size; ++i) {
      Nan::Set(result, Nan::New<Number>(i), ConvenientPatch::New((void *)baton->out->at(i)));
    }

    delete baton->out;

    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);

    return;
  }

  if (baton->error) {
    Local<v8::Object> err;
    if (baton->error->message) {
      err = Nan::Error(baton->error->message)->ToObject();
    } else {
      err = Nan::Error("Method convenientFromDiff has thrown an error.")->ToObject();
    }
    err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
    Local<v8::Value> argv[1] = {
      err
    };
    callback->Call(1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);

    return;
  }

  if (baton->error_code < 0) {
    Local<v8::Object> err = Nan::Error("method convenientFromDiff has thrown an error.")->ToObject();
    err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
    Local<v8::Value> argv[1] = {
      err
    };
    callback->Call(1, argv);

    return;
  }

  callback->Call(0, NULL);
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitPatchTraits>;
 