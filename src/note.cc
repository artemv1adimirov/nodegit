// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/note.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/signature.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
  #include "../include/note_iterator.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitNote::~GitNote() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                         }

  void GitNote::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Note").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "author", Author);
            Nan::SetPrototypeMethod(tpl, "committer", Committer);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "foreach", Foreach);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "id", Id);
             Nan::SetMethod(tpl, "iteratorNew", IteratorNew);
            Nan::SetPrototypeMethod(tpl, "message", Message);
             Nan::SetMethod(tpl, "next", Next);
             Nan::SetMethod(tpl, "read", Read);
             Nan::SetMethod(tpl, "remove", Remove);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Note").ToLocalChecked(), _constructor_template);
  }

  
/*
     * @return Signature  result    */
NAN_METHOD(GitNote::Author) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
);

    const git_signature * result = git_note_author(
  Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New(result, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Signature  result    */
NAN_METHOD(GitNote::Committer) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
);

    const git_signature * result = git_note_committer(
  Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New(result, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Repository repo
   * @param String notes_ref
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
   * @param String note
   * @param Number force
    * @param Oid callback
   */
NAN_METHOD(GitNote::Create) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String notes_ref is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 4
    || (!info[4]->IsObject() && !info[4]->IsString())) {
    return Nan::ThrowError("Oid oid is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
    return Nan::ThrowError("String note is required.");
  }

  if (info.Length() == 6 || !info[6]->IsNumber()) {
    return Nan::ThrowError("Number force is required.");
  }

  if (info.Length() == 7 || !info[7]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  String::Utf8Value notes_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, *notes_ref, notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
  baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[3]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->committer = from_committer;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[4]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_oid = oidOut;
  }
  else {
from_oid = Nan::ObjectWrap::Unwrap<GitOid>(info[4]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->oid = from_oid;
  baton->oidNeedsFree = info[4]->IsString();
// start convert_from_v8 block
  const char * from_note = NULL;

  String::Utf8Value note(info[5]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_note = (const char *) malloc(note.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_note, *note, note.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_note) + note.length()), 0, 1);
// end convert_from_v8 block
  baton->note = from_note;
// start convert_from_v8 block
  int from_force;
  from_force = (int)   info[6]->ToNumber()->Value();
// end convert_from_v8 block
  baton->force = from_force;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[7]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("notes_ref", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("author", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("committer", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("oid", info[4]->ToObject());
  if (!info[5]->IsUndefined() && !info[5]->IsNull())
    worker->SaveToPersistent("note", info[5]->ToObject());
  if (!info[6]->IsUndefined() && !info[6]->IsNull())
    worker->SaveToPersistent("force", info[6]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitNote::CreateWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->repo
        ,baton->notes_ref
        ,baton->author
        ,baton->committer
        ,baton->oid
        ,baton->note
);

  int result = git_note_create(
baton->out,baton->repo,baton->notes_ref,baton->author,baton->committer,baton->oid,baton->note,baton->force    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitNote::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOid baton->out
       to = GitOid::New(baton->out, true  );
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
      workerArguments.push(GetFromPersistent("notes_ref"));
      workerArguments.push(GetFromPersistent("author"));
      workerArguments.push(GetFromPersistent("committer"));
      workerArguments.push(GetFromPersistent("oid"));
      workerArguments.push(GetFromPersistent("note"));
      workerArguments.push(GetFromPersistent("force"));
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

  if (baton->oidNeedsFree) {
    baton->oidNeedsFree = false;
    free((void *)baton->oid);
  }

  delete baton;
}

  
/*
 * @param Repository repo
   * @param String notes_ref
   * @param NoteForeachCb note_cb
   * @param Void payload
     */
NAN_METHOD(GitNote::Foreach) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String notes_ref is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("NoteForeachCb note_cb is required.");
  }
  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ForeachBaton* baton = new ForeachBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  Foreach_globalPayload* globalPayload = new Foreach_globalPayload;
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  String::Utf8Value notes_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, *notes_ref, notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
  baton->notes_ref = from_notes_ref;
  if (!info[2]->IsFunction()) {
    baton->note_cb = NULL;
    globalPayload->note_cb = NULL;
  }
  else {
    baton->note_cb = Foreach_note_cb_cppCallback;
    globalPayload->note_cb = new Nan::Callback(info[2].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[4]));
  ForeachWorker *worker = new ForeachWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("notes_ref", info[1]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("payload", info[3]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitNote::ForeachWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->notes_ref
        ,baton->payload
);

  int result = git_note_foreach(
baton->repo,baton->notes_ref,baton->note_cb,baton->payload    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitNote::ForeachWorker::HandleOKCallback() {
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
        err = Nan::Error("Method foreach has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("notes_ref"));
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
        v8::Local<v8::Object> err = Nan::Error("Method foreach has thrown an error.")->ToObject();
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

  delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}


int GitNote::Foreach_note_cb_cppCallback (
    const git_oid * blob_id,     const git_oid * annotated_object_id,     void * payload  ) {
  Foreach_NoteCbBaton baton(0);

    baton.blob_id = blob_id;
    baton.annotated_object_id = annotated_object_id;
    baton.payload = payload;
 
  return baton.ExecuteAsync(Foreach_note_cb_async);
}

void GitNote::Foreach_note_cb_async(void *untypedBaton) {
  Nan::HandleScope scope;

  Foreach_NoteCbBaton* baton = static_cast<Foreach_NoteCbBaton*>(untypedBaton);

    Nan::Callback* callback = ((Foreach_globalPayload*)baton->payload)->note_cb;
   
  v8::Local<Value> argv[3] = {
          GitOid::New(baton->blob_id, false),
            GitOid::New(baton->annotated_object_id, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  v8::Local<v8::Value> result = callback->Call(3, argv);

  if(PromiseCompletion::ForwardIfPromise(result, baton, Foreach_note_cb_promiseCompleted)) {
    return;
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
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

void GitNote::Foreach_note_cb_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
  Nan::HandleScope scope;

  Foreach_NoteCbBaton* baton = static_cast<Foreach_NoteCbBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
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
    GitNote* instance = static_cast<GitNote*>(baton->  payload  );
    v8::Local<v8::Object> parent = instance->handle();
    SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
     */
NAN_METHOD(GitNote::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
);

git_note_free(
  Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitNote::Id) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
);

    const git_oid * result = git_note_id(
  Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New(result, true , info.This() );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Repository repo
   * @param String notes_ref
    * @param NoteIterator callback
   */
NAN_METHOD(GitNote::IteratorNew) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String notes_ref is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  IteratorNewBaton* baton = new IteratorNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  String::Utf8Value notes_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, *notes_ref, notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
  baton->notes_ref = from_notes_ref;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  IteratorNewWorker *worker = new IteratorNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("notes_ref", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitNote::IteratorNewWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->notes_ref
);

  int result = git_note_iterator_new(
&baton->out,baton->repo,baton->notes_ref    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitNote::IteratorNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitNoteIterator baton->out
       to = GitNoteIterator::New(baton->out, false  );
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
        err = Nan::Error("Method iteratorNew has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("notes_ref"));
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
        v8::Local<v8::Object> err = Nan::Error("Method iteratorNew has thrown an error.")->ToObject();
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
NAN_METHOD(GitNote::Message) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
);

    const char * result = git_note_message(
  Nan::ObjectWrap::Unwrap<GitNote>(info.This())->GetValue()
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
 * @param Oid note_id
   * @param Oid annotated_id
   * @param NoteIterator it
     * @return Number  result    */
NAN_METHOD(GitNote::Next) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid note_id is required.");
  }
  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid annotated_id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("NoteIterator it is required.");
  }

// start convert_from_v8 block
  git_oid * from_note_id = NULL;
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

    from_note_id = oidOut;
  }
  else {
from_note_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_oid * from_annotated_id = NULL;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_annotated_id = oidOut;
  }
  else {
from_annotated_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_note_iterator * from_it = NULL;
from_it = Nan::ObjectWrap::Unwrap<GitNoteIterator>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_note_id
        ,    from_annotated_id
        ,    from_it
);

    int result = git_note_next(
  from_note_id
,  from_annotated_id
,  from_it
    );

     if (info[0]->IsString()) {
      free((void *)from_note_id);
    }
    if (info[1]->IsString()) {
      free((void *)from_annotated_id);
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param Repository repo
   * @param String notes_ref
   * @param Oid oid
    * @param Note callback
   */
NAN_METHOD(GitNote::Read) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String notes_ref is required.");
  }

  if (info.Length() == 2
    || (!info[2]->IsObject() && !info[2]->IsString())) {
    return Nan::ThrowError("Oid oid is required.");
  }
  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ReadBaton* baton = new ReadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  String::Utf8Value notes_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, *notes_ref, notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
  baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[2]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[2]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_oid = oidOut;
  }
  else {
from_oid = Nan::ObjectWrap::Unwrap<GitOid>(info[2]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->oid = from_oid;
  baton->oidNeedsFree = info[2]->IsString();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  ReadWorker *worker = new ReadWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("notes_ref", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("oid", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitNote::ReadWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->notes_ref
        ,baton->oid
);

  int result = git_note_read(
&baton->out,baton->repo,baton->notes_ref,baton->oid    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitNote::ReadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitNote baton->out
       to = GitNote::New(baton->out, false  );
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
        err = Nan::Error("Method read has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("notes_ref"));
      workerArguments.push(GetFromPersistent("oid"));
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
        v8::Local<v8::Object> err = Nan::Error("Method read has thrown an error.")->ToObject();
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

  if (baton->oidNeedsFree) {
    baton->oidNeedsFree = false;
    free((void *)baton->oid);
  }

  delete baton;
}

  
/*
 * @param Repository repo
   * @param String notes_ref
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
     */
NAN_METHOD(GitNote::Remove) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String notes_ref is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 4
    || (!info[4]->IsObject() && !info[4]->IsString())) {
    return Nan::ThrowError("Oid oid is required.");
  }
  if (info.Length() == 5 || !info[5]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RemoveBaton* baton = new RemoveBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  String::Utf8Value notes_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, *notes_ref, notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
  baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[3]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->committer = from_committer;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[4]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_oid = oidOut;
  }
  else {
from_oid = Nan::ObjectWrap::Unwrap<GitOid>(info[4]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->oid = from_oid;
  baton->oidNeedsFree = info[4]->IsString();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[5]));
  RemoveWorker *worker = new RemoveWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("notes_ref", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("author", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("committer", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("oid", info[4]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitNote::RemoveWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->notes_ref
        ,baton->author
        ,baton->committer
        ,baton->oid
);

  int result = git_note_remove(
baton->repo,baton->notes_ref,baton->author,baton->committer,baton->oid    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitNote::RemoveWorker::HandleOKCallback() {
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
        err = Nan::Error("Method remove has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("notes_ref"));
      workerArguments.push(GetFromPersistent("author"));
      workerArguments.push(GetFromPersistent("committer"));
      workerArguments.push(GetFromPersistent("oid"));
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
        v8::Local<v8::Object> err = Nan::Error("Method remove has thrown an error.")->ToObject();
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

  if (baton->oidNeedsFree) {
    baton->oidNeedsFree = false;
    free((void *)baton->oid);
  }

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitNoteTraits>;
 