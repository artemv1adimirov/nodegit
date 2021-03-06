// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/revwalk.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/commit.h"
  #include "../include/functions/copy.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRevwalk::~GitRevwalk() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                        }

  void GitRevwalk::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Revwalk").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "hide", Hide);
            Nan::SetPrototypeMethod(tpl, "hideGlob", HideGlob);
            Nan::SetPrototypeMethod(tpl, "hideHead", HideHead);
            Nan::SetPrototypeMethod(tpl, "hideRef", HideRef);
             Nan::SetMethod(tpl, "create", Create);
            Nan::SetPrototypeMethod(tpl, "next", Next);
            Nan::SetPrototypeMethod(tpl, "push", Push);
            Nan::SetPrototypeMethod(tpl, "pushGlob", PushGlob);
            Nan::SetPrototypeMethod(tpl, "pushHead", PushHead);
            Nan::SetPrototypeMethod(tpl, "pushRange", PushRange);
            Nan::SetPrototypeMethod(tpl, "pushRef", PushRef);
            Nan::SetPrototypeMethod(tpl, "repository", Repository);
            Nan::SetPrototypeMethod(tpl, "reset", Reset);
            Nan::SetPrototypeMethod(tpl, "simplifyFirstParent", SimplifyFirstParent);
            Nan::SetPrototypeMethod(tpl, "sorting", Sorting);
            Nan::SetPrototypeMethod(tpl, "fastWalk", FastWalk);
            Nan::SetPrototypeMethod(tpl, "fileHistoryWalk", FileHistoryWalk);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Revwalk").ToLocalChecked(), _constructor_template);
  }

  
/*
     */
NAN_METHOD(GitRevwalk::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

git_revwalk_free(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
   * @param Oid commit_id
     * @return Number  result    */
NAN_METHOD(GitRevwalk::Hide) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid commit_id is required.");
  }
// start convert_from_v8 block
  const git_oid * from_commit_id = NULL;
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

    from_commit_id = oidOut;
  }
  else {
from_commit_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_commit_id
);

    int result = git_revwalk_hide(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_commit_id
    );

     if (info[0]->IsString()) {
      free((void *)from_commit_id);
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String glob
     * @return Number  result    */
NAN_METHOD(GitRevwalk::HideGlob) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String glob is required.");
  }

// start convert_from_v8 block
  const char * from_glob = NULL;

  String::Utf8Value glob(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_glob = (const char *) malloc(glob.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_glob, *glob, glob.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_glob) + glob.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_glob
);

    int result = git_revwalk_hide_glob(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_glob
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
NAN_METHOD(GitRevwalk::HideHead) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

    int result = git_revwalk_hide_head(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRevwalk::HideRef) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

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
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_refname
);

    int result = git_revwalk_hide_ref(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_refname
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
     * @return Revwalk out    */
NAN_METHOD(GitRevwalk::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  git_revwalk * out = 0;
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_repo
);

git_revwalk_new(
&  out
,  from_repo
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitRevwalk out
       to = GitRevwalk::New(out, true  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
     * @param Oid callback
   */
NAN_METHOD(GitRevwalk::Next) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NextBaton* baton = new NextBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_oid *)malloc(sizeof(git_oid ));
  baton->walk = Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  NextWorker *worker = new NextWorker(baton, callback);
  worker->SaveToPersistent("walk", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitRevwalk::NextWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->walk
);

  int result = git_revwalk_next(
baton->out,baton->walk    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitRevwalk::NextWorker::HandleOKCallback() {
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
        err = Nan::Error("Method next has thrown an error.")->ToObject();
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
        v8::Local<v8::Object> err = Nan::Error("Method next has thrown an error.")->ToObject();
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
   * @param Oid id
     * @return Number  result    */
NAN_METHOD(GitRevwalk::Push) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
// start convert_from_v8 block
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_id
);

    int result = git_revwalk_push(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_id
    );

     if (info[0]->IsString()) {
      free((void *)from_id);
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String glob
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushGlob) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String glob is required.");
  }

// start convert_from_v8 block
  const char * from_glob = NULL;

  String::Utf8Value glob(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_glob = (const char *) malloc(glob.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_glob, *glob, glob.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_glob) + glob.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_glob
);

    int result = git_revwalk_push_glob(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_glob
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
NAN_METHOD(GitRevwalk::PushHead) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

    int result = git_revwalk_push_head(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String range
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushRange) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String range is required.");
  }

// start convert_from_v8 block
  const char * from_range = NULL;

  String::Utf8Value range(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_range = (const char *) malloc(range.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_range, *range, range.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_range) + range.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_range
);

    int result = git_revwalk_push_range(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_range
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushRef) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

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
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
        ,    from_refname
);

    int result = git_revwalk_push_ref(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_refname
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Repository  result    */
NAN_METHOD(GitRevwalk::Repository) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

    git_repository * result = git_revwalk_repository(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
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
     */
NAN_METHOD(GitRevwalk::Reset) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

git_revwalk_reset(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
     */
NAN_METHOD(GitRevwalk::SimplifyFirstParent) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

git_revwalk_simplify_first_parent(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
   * @param Number sort_mode
     */
NAN_METHOD(GitRevwalk::Sorting) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number sort_mode is required.");
  }

// start convert_from_v8 block
  unsigned int from_sort_mode;
  from_sort_mode = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
);

git_revwalk_sorting(
  Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,  from_sort_mode
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
        NAN_METHOD(GitRevwalk::FastWalk)
{
  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Max count is required and must be a number.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FastWalkBaton* baton = new FastWalkBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->max_count = (unsigned int)info[0]->ToNumber()->Value();
  baton->out = new std::vector<git_oid*>;
  baton->out->reserve(baton->max_count);
  baton->walk = Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  FastWalkWorker *worker = new FastWalkWorker(baton, callback);
  worker->SaveToPersistent("fastWalk", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRevwalk::FastWalkWorker::Execute()
{
  for (int i = 0; i < baton->max_count; i++)
  {
    git_oid *nextCommit = (git_oid *)malloc(sizeof(git_oid));
    giterr_clear();
    baton->error_code = git_revwalk_next(nextCommit, baton->walk);

    if (baton->error_code != GIT_OK)
    {
      // We couldn't get a commit out of the revwalk. It's either in
      // an error state or there aren't anymore commits in the revwalk.
      free(nextCommit);

      if (baton->error_code != GIT_ITEROVER) {
        baton->error = git_error_dup(giterr_last());

        while(!baton->out->empty())
        {
          // part of me wants to #define shoot free so we can take the
          // baton out back and shoot the oids
          git_oid *oidToFree = baton->out->back();
          free(oidToFree);
          baton->out->pop_back();
        }

        delete baton->out;

        baton->out = NULL;
      }
      else {
        baton->error_code = GIT_OK;
      }

      break;
    }

    baton->out->push_back(nextCommit);
  }
}

void GitRevwalk::FastWalkWorker::HandleOKCallback()
{
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Local<Array> result = Nan::New<Array>(size);
    for (unsigned int i = 0; i < size; i++) {
      Nan::Set(result, Nan::New<Number>(i), GitOid::New(baton->out->at(i), true));
    }

    delete baton->out;

    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  }
  else
  {
    if (baton->error)
    {
      Local<v8::Object> err;
      if (baton->error->message) {
        err = Nan::Error(baton->error->message)->ToObject();
      } else {
        err = Nan::Error("Method fastWalk has thrown an error.")->ToObject();
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
    }
    else if (baton->error_code < 0)
    {
      std::queue< Local<v8::Value> > workerArguments;
      bool callbackFired = false;

      while(!workerArguments.empty())
      {
        Local<v8::Value> node = workerArguments.front();
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
        )
        {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = GetPrivate(nodeObj, Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined())
        {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex)
        {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined())
          {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired)
      {
        Local<v8::Object> err = Nan::Error("Method next has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    }
    else
    {
      callback->Call(0, NULL);
    }
  }
}

        NAN_METHOD(GitRevwalk::FileHistoryWalk)
{
  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("File path to get the history is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Max count is required and must be a number.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FileHistoryWalkBaton* baton = new FileHistoryWalkBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;
  String::Utf8Value from_js_file_path(info[0]->ToString());
  baton->file_path = strdup(*from_js_file_path);
  baton->max_count = (unsigned int)info[1]->ToNumber()->Value();
  baton->out = new std::vector< std::pair<git_commit *, std::pair<char *, git_delta_t> > *>;
  baton->out->reserve(baton->max_count);
  baton->walk = Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  FileHistoryWalkWorker *worker = new FileHistoryWalkWorker(baton, callback);
  worker->SaveToPersistent("fileHistoryWalk", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRevwalk::FileHistoryWalkWorker::Execute()
{
  git_repository *repo = git_revwalk_repository(baton->walk);
  git_oid *nextOid = (git_oid *)malloc(sizeof(git_oid));
  giterr_clear();
  for (
    unsigned int i = 0;
    i < baton->max_count && (baton->error_code = git_revwalk_next(nextOid, baton->walk)) == GIT_OK;
    ++i
  ) {
    // check if this commit has the file
    git_commit *nextCommit;

    if ((baton->error_code = git_commit_lookup(&nextCommit, repo, nextOid)) != GIT_OK) {
      break;
    }

    git_tree *thisTree, *parentTree;
    if ((baton->error_code = git_commit_tree(&thisTree, nextCommit)) != GIT_OK) {
      git_commit_free(nextCommit);
      break;
    }

    git_diff *diffs;
    git_diff_options opts = GIT_DIFF_OPTIONS_INIT;
    char *file_path = strdup(baton->file_path);
    opts.pathspec.strings = &file_path;
    opts.pathspec.count = 1;
    git_commit *parent;
    unsigned int parents = git_commit_parentcount(nextCommit);
    if (parents > 1) {
      git_commit_free(nextCommit);
      continue;
    } else if (parents == 1) {
      if ((baton->error_code = git_commit_parent(&parent, nextCommit, 0)) != GIT_OK) {
        git_commit_free(nextCommit);
        break;
      }
      if (
        (baton->error_code = git_commit_tree(&parentTree, parent)) != GIT_OK ||
        (baton->error_code = git_diff_tree_to_tree(&diffs, repo, parentTree, thisTree, &opts)) != GIT_OK
      ) {
        git_commit_free(nextCommit);
        git_commit_free(parent);
        break;
      }
    } else {
      if ((baton->error_code = git_diff_tree_to_tree(&diffs, repo, NULL, thisTree, &opts)) != GIT_OK) {
        git_commit_free(nextCommit);
        break;
      }
    }

    free(file_path);
    opts.pathspec.strings = NULL;
    opts.pathspec.count = 0;

    bool flag = false;
    bool doRenamedPass = false;
    unsigned int numDeltas = git_diff_num_deltas(diffs);
    for (unsigned int j = 0; j < numDeltas; ++j) {
      git_patch *nextPatch;
      baton->error_code = git_patch_from_diff(&nextPatch, diffs, j);

      if (baton->error_code < GIT_OK) {
        break;
      }

      if (nextPatch == NULL) {
        continue;
      }

      const git_diff_delta *delta = git_patch_get_delta(nextPatch);
      bool isEqualOldFile = !strcmp(delta->old_file.path, baton->file_path);
      bool isEqualNewFile = !strcmp(delta->new_file.path, baton->file_path);

      if (isEqualNewFile) {
        if (delta->status == GIT_DELTA_ADDED || delta->status == GIT_DELTA_DELETED) {
          doRenamedPass = true;
          break;
        }
        std::pair<git_commit *, std::pair<char *, git_delta_t> > *historyEntry;
        if (!isEqualOldFile) {
          historyEntry = new std::pair<git_commit *, std::pair<char *, git_delta_t> >(
            nextCommit,
            std::pair<char *, git_delta_t>(strdup(delta->old_file.path), delta->status)
          );
        } else {
          historyEntry = new std::pair<git_commit *, std::pair<char *, git_delta_t> >(
            nextCommit,
            std::pair<char *, git_delta_t>(strdup(delta->new_file.path), delta->status)
          );
        }
        baton->out->push_back(historyEntry);
        flag = true;
      }

      git_patch_free(nextPatch);

      if (flag) {
        break;
      }
    }

    if (doRenamedPass) {
      git_diff_free(diffs);

      if (parents == 1) {
        if ((baton->error_code = git_diff_tree_to_tree(&diffs, repo, parentTree, thisTree, NULL)) != GIT_OK) {
          git_commit_free(nextCommit);
          break;
        }
        if ((baton->error_code = git_diff_find_similar(diffs, NULL)) != GIT_OK) {
          git_commit_free(nextCommit);
          break;
        }
      } else {
        if ((baton->error_code = git_diff_tree_to_tree(&diffs, repo, NULL, thisTree, NULL)) != GIT_OK) {
          git_commit_free(nextCommit);
          break;
        }
        if((baton->error_code = git_diff_find_similar(diffs, NULL)) != GIT_OK) {
          git_commit_free(nextCommit);
          break;
        }
      }

      flag = false;
      numDeltas = git_diff_num_deltas(diffs);
      for (unsigned int j = 0; j < numDeltas; ++j) {
        git_patch *nextPatch;
        baton->error_code = git_patch_from_diff(&nextPatch, diffs, j);

        if (baton->error_code < GIT_OK) {
          break;
        }

        if (nextPatch == NULL) {
          continue;
        }

        const git_diff_delta *delta = git_patch_get_delta(nextPatch);
        bool isEqualOldFile = !strcmp(delta->old_file.path, baton->file_path);
        bool isEqualNewFile = !strcmp(delta->new_file.path, baton->file_path);
        int oldLen = strlen(delta->old_file.path);
        int newLen = strlen(delta->new_file.path);
        char *outPair = new char[oldLen + newLen + 2];
        strcpy(outPair, delta->new_file.path);
        outPair[newLen] = '\n';
        outPair[newLen + 1] = '\0';
        strcat(outPair, delta->old_file.path);

        if (isEqualNewFile) {
          std::pair<git_commit *, std::pair<char *, git_delta_t> > *historyEntry;
          if (!isEqualOldFile) {
            historyEntry = new std::pair<git_commit *, std::pair<char *, git_delta_t> >(
              nextCommit,
              std::pair<char *, git_delta_t>(strdup(outPair), delta->status)
            );
          } else {
            historyEntry = new std::pair<git_commit *, std::pair<char *, git_delta_t> >(
              nextCommit,
              std::pair<char *, git_delta_t>(strdup(delta->new_file.path), delta->status)
            );
          }
          baton->out->push_back(historyEntry);
          flag = true;
        } else if (isEqualOldFile) {
          std::pair<git_commit *, std::pair<char *, git_delta_t> > *historyEntry;
          historyEntry = new std::pair<git_commit *, std::pair<char *, git_delta_t> >(
            nextCommit,
            std::pair<char *, git_delta_t>(strdup(outPair), delta->status)
          );
          baton->out->push_back(historyEntry);
          flag = true;
        }

        delete[] outPair;

        git_patch_free(nextPatch);

        if (flag) {
          break;
        }
      }
    }

    git_diff_free(diffs);

    if (!flag && nextCommit != NULL) {
      git_commit_free(nextCommit);
    }

    if (baton->error_code != GIT_OK) {
      break;
    }
  }

  free(nextOid);

  if (baton->error_code != GIT_OK) {
    if (baton->error_code != GIT_ITEROVER) {
      baton->error = git_error_dup(giterr_last());

      while(!baton->out->empty())
      {
        std::pair<git_commit *, std::pair<char *, git_delta_t> > *pairToFree = baton->out->back();
        baton->out->pop_back();
        git_commit_free(pairToFree->first);
        free(pairToFree->second.first);
        free(pairToFree);
      }

      delete baton->out;

      baton->out = NULL;
    }
  } else {
    baton->error_code = GIT_OK;
  }
}

void GitRevwalk::FileHistoryWalkWorker::HandleOKCallback()
{
  if (baton->out != NULL) {
    unsigned int size = baton->out->size();
    Local<Array> result = Nan::New<Array>(size);
    for (unsigned int i = 0; i < size; i++) {
      Local<v8::Object> historyEntry = Nan::New<Object>();
      std::pair<git_commit *, std::pair<char *, git_delta_t> > *batonResult = baton->out->at(i);
      Nan::Set(historyEntry, Nan::New("commit").ToLocalChecked(), GitCommit::New(batonResult->first, true));
      Nan::Set(historyEntry, Nan::New("status").ToLocalChecked(), Nan::New<Number>(batonResult->second.second));
      if (batonResult->second.second == GIT_DELTA_RENAMED) {
        char *namePair = batonResult->second.first;
        char *split = strchr(namePair, '\n');
        *split = '\0';
        char *oldName = split + 1;

        Nan::Set(historyEntry, Nan::New("oldName").ToLocalChecked(), Nan::New(oldName).ToLocalChecked());
        Nan::Set(historyEntry, Nan::New("newName").ToLocalChecked(), Nan::New(namePair).ToLocalChecked());
      }
      Nan::Set(result, Nan::New<Number>(i), historyEntry);

      free(batonResult->second.first);
      free(batonResult);
    }

    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);

    delete baton->out;
    return;
  }

  if (baton->error) {
    Local<v8::Object> err;
    if (baton->error->message) {
      err = Nan::Error(baton->error->message)->ToObject();
    } else {
      err = Nan::Error("Method fileHistoryWalk has thrown an error.")->ToObject();
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
    Local<v8::Object> err = Nan::Error("Method next has thrown an error.")->ToObject();
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
template class NodeGitWrapper<GitRevwalkTraits>;
 