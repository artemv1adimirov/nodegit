// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/commit.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/tree.h"
  #include "../include/repository.h"
  #include "../include/buf.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCommit::~GitCommit() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                              }

  void GitCommit::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Commit").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "amend", Amend);
            Nan::SetPrototypeMethod(tpl, "author", Author);
            Nan::SetPrototypeMethod(tpl, "body", Body);
            Nan::SetPrototypeMethod(tpl, "committer", Committer);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "createV", CreateV);
             Nan::SetMethod(tpl, "createWithSignature", CreateWithSignature);
            Nan::SetPrototypeMethod(tpl, "dup", Dup);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "headerField", HeaderField);
            Nan::SetPrototypeMethod(tpl, "id", Id);
             Nan::SetMethod(tpl, "lookup", Lookup);
             Nan::SetMethod(tpl, "lookupPrefix", LookupPrefix);
            Nan::SetPrototypeMethod(tpl, "message", Message);
            Nan::SetPrototypeMethod(tpl, "messageEncoding", MessageEncoding);
            Nan::SetPrototypeMethod(tpl, "messageRaw", MessageRaw);
            Nan::SetPrototypeMethod(tpl, "nthGenAncestor", NthGenAncestor);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "parent", Parent);
            Nan::SetPrototypeMethod(tpl, "parentId", ParentId);
            Nan::SetPrototypeMethod(tpl, "parentcount", Parentcount);
            Nan::SetPrototypeMethod(tpl, "rawHeader", RawHeader);
            Nan::SetPrototypeMethod(tpl, "summary", Summary);
            Nan::SetPrototypeMethod(tpl, "time", Time);
            Nan::SetPrototypeMethod(tpl, "timeOffset", TimeOffset);
            Nan::SetPrototypeMethod(tpl, "tree", Tree);
            Nan::SetPrototypeMethod(tpl, "treeId", TreeId);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Commit").ToLocalChecked(), _constructor_template);
  }

 
/*
    * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
    * @param Oid callback
   */
NAN_METHOD(GitCommit::Amend) {

  if (info.Length() == 6 || !info[6]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  AmendBaton* baton = new AmendBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->id = (git_oid *)malloc(sizeof(git_oid ));
  baton->commit_to_amend = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_update_ref = NULL;
    if (info[0]->IsString()) {

  String::Utf8Value update_ref(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, *update_ref, update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
  baton->update_ref = from_update_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
    if (info[1]->IsObject()) {
from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[1]->ToObject())->GetValue();
  }
  else {
    from_author = 0;
  }
// end convert_from_v8 block
  baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
    if (info[2]->IsObject()) {
from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[2]->ToObject())->GetValue();
  }
  else {
    from_committer = 0;
  }
// end convert_from_v8 block
  baton->committer = from_committer;
// start convert_from_v8 block
  const char * from_message_encoding = NULL;
    if (info[3]->IsString()) {

  String::Utf8Value message_encoding(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, *message_encoding, message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
  baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;
    if (info[4]->IsString()) {

  String::Utf8Value message(info[4]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, *message, message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
  }
  else {
    from_message = 0;
  }
// end convert_from_v8 block
  baton->message = from_message;
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
    if (info[5]->IsObject()) {
from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[5]->ToObject())->GetValue();
  }
  else {
    from_tree = 0;
  }
// end convert_from_v8 block
  baton->tree = from_tree;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[6]));
  AmendWorker *worker = new AmendWorker(baton, callback);
  worker->SaveToPersistent("commit_to_amend", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("update_ref", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("author", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("committer", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("message_encoding", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("message", info[4]->ToObject());
  if (!info[5]->IsUndefined() && !info[5]->IsNull())
    worker->SaveToPersistent("tree", info[5]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::AmendWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->id
        ,baton->commit_to_amend
        ,baton->update_ref
        ,baton->author
        ,baton->committer
        ,baton->message_encoding
        ,baton->message
        ,baton->tree
);

  int result = git_commit_amend(
baton->id,baton->commit_to_amend,baton->update_ref,baton->author,baton->committer,baton->message_encoding,baton->message,baton->tree    );

  }
}

void GitCommit::AmendWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->id != NULL) {
    // GitOid baton->id
       to = GitOid::New(baton->id, true  );
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
        err = Nan::Error("Method amend has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("update_ref"));
      workerArguments.push(GetFromPersistent("author"));
      workerArguments.push(GetFromPersistent("committer"));
      workerArguments.push(GetFromPersistent("message_encoding"));
      workerArguments.push(GetFromPersistent("message"));
      workerArguments.push(GetFromPersistent("tree"));
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
        v8::Local<v8::Object> err = Nan::Error("Method amend has thrown an error.")->ToObject();
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
     * @return Signature  result    */
NAN_METHOD(GitCommit::Author) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const git_signature * result = git_commit_author(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New(result, false , info.This() );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::Body) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_body(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
     * @return Signature  result    */
NAN_METHOD(GitCommit::Committer) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const git_signature * result = git_commit_committer(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
    );

     // null checks on pointers
    if (!result) {
      return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
    }

    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New(result, false , info.This() );
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
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
   * @param Array parents
    * @param Oid callback
   */
NAN_METHOD(GitCommit::Create) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 5 || !info[5]->IsString()) {
    return Nan::ThrowError("String message is required.");
  }

  if (info.Length() == 6 || !info[6]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

  if (info.Length() == 7 || !info[7]->IsNumber()) {
    return Nan::ThrowError("Number parent_count is required.");
  }

  if (info.Length() == 8 || !info[8]->IsObject()) {
    return Nan::ThrowError("Array parents is required.");
  }

  if (info.Length() == 9 || !info[9]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->id = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_update_ref = NULL;
    if (info[1]->IsString()) {

  String::Utf8Value update_ref(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, *update_ref, update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
  baton->update_ref = from_update_ref;
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
  const char * from_message_encoding = NULL;
    if (info[4]->IsString()) {

  String::Utf8Value message_encoding(info[4]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, *message_encoding, message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
  baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;

  String::Utf8Value message(info[5]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, *message, message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
  baton->message = from_message;
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[6]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->tree = from_tree;
// start convert_from_v8 block
  size_t from_parent_count;
  from_parent_count = (size_t)   info[7]->ToNumber()->Value();
// end convert_from_v8 block
  baton->parent_count = from_parent_count;
// start convert_from_v8 block
  const git_commit ** from_parents = NULL;

  Array *tmp_parents = Array::Cast(*info[8]);
  from_parents = (const git_commit **)malloc(tmp_parents->Length() * sizeof(const git_commit *));
      for (unsigned int i = 0; i < tmp_parents->Length(); i++) {
      from_parents[i] = Nan::ObjectWrap::Unwrap<GitCommit>(tmp_parents->Get(Nan::New(static_cast<double>(i)))->ToObject())->GetValue();
      }
// end convert_from_v8 block
  baton->parents = from_parents;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[9]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("update_ref", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("author", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("committer", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("message_encoding", info[4]->ToObject());
  if (!info[5]->IsUndefined() && !info[5]->IsNull())
    worker->SaveToPersistent("message", info[5]->ToObject());
  if (!info[6]->IsUndefined() && !info[6]->IsNull())
    worker->SaveToPersistent("tree", info[6]->ToObject());
  if (!info[7]->IsUndefined() && !info[7]->IsNull())
    worker->SaveToPersistent("parent_count", info[7]->ToObject());
  if (!info[8]->IsUndefined() && !info[8]->IsNull())
    worker->SaveToPersistent("parents", info[8]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::CreateWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->id
        ,baton->repo
        ,baton->update_ref
        ,baton->author
        ,baton->committer
        ,baton->message_encoding
        ,baton->message
        ,baton->tree
);

  int result = git_commit_create(
baton->id,baton->repo,baton->update_ref,baton->author,baton->committer,baton->message_encoding,baton->message,baton->tree,baton->parent_count,baton->parents    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->id != NULL) {
    // GitOid baton->id
       to = GitOid::New(baton->id, true  );
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
      workerArguments.push(GetFromPersistent("update_ref"));
      workerArguments.push(GetFromPersistent("author"));
      workerArguments.push(GetFromPersistent("committer"));
      workerArguments.push(GetFromPersistent("message_encoding"));
      workerArguments.push(GetFromPersistent("message"));
      workerArguments.push(GetFromPersistent("tree"));
      workerArguments.push(GetFromPersistent("parent_count"));
      workerArguments.push(GetFromPersistent("parents"));
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
 * @param Oid id
   * @param Repository repo
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
     * @return Number  result    */
NAN_METHOD(GitCommit::CreateV) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String update_ref is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 4 || !info[4]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 5 || !info[5]->IsString()) {
    return Nan::ThrowError("String message_encoding is required.");
  }

  if (info.Length() == 6 || !info[6]->IsString()) {
    return Nan::ThrowError("String message is required.");
  }

  if (info.Length() == 7 || !info[7]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

  if (info.Length() == 8 || !info[8]->IsNumber()) {
    return Nan::ThrowError("Number parent_count is required.");
  }

// start convert_from_v8 block
  git_oid * from_id = NULL;
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
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_update_ref = NULL;

  String::Utf8Value update_ref(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, *update_ref, update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[3]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[4]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding = NULL;

  String::Utf8Value message_encoding(info[5]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, *message_encoding, message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message = NULL;

  String::Utf8Value message(info[6]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, *message, message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[7]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_parent_count;
  from_parent_count = (size_t)   info[8]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_id
        ,    from_repo
        ,    from_update_ref
        ,    from_author
        ,    from_committer
        ,    from_message_encoding
        ,    from_message
        ,    from_tree
);

    int result = git_commit_create_v(
  from_id
,  from_repo
,  from_update_ref
,  from_author
,  from_committer
,  from_message_encoding
,  from_message
,  from_tree
,  from_parent_count
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
  * @param Repository repo
   * @param String commit_content
   * @param String signature
   * @param String signature_field
    * @param Oid callback
   */
NAN_METHOD(GitCommit::CreateWithSignature) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String commit_content is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String signature is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String signature_field is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateWithSignatureBaton* baton = new CreateWithSignatureBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_commit_content = NULL;

  String::Utf8Value commit_content(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_commit_content = (const char *) malloc(commit_content.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_commit_content, *commit_content, commit_content.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_commit_content) + commit_content.length()), 0, 1);
// end convert_from_v8 block
  baton->commit_content = from_commit_content;
// start convert_from_v8 block
  const char * from_signature = NULL;

  String::Utf8Value signature(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_signature = (const char *) malloc(signature.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_signature, *signature, signature.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_signature) + signature.length()), 0, 1);
// end convert_from_v8 block
  baton->signature = from_signature;
// start convert_from_v8 block
  const char * from_signature_field = NULL;

  String::Utf8Value signature_field(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_signature_field = (const char *) malloc(signature_field.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_signature_field, *signature_field, signature_field.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_signature_field) + signature_field.length()), 0, 1);
// end convert_from_v8 block
  baton->signature_field = from_signature_field;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[4]));
  CreateWithSignatureWorker *worker = new CreateWithSignatureWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("commit_content", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("signature", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("signature_field", info[3]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::CreateWithSignatureWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->repo
        ,baton->commit_content
        ,baton->signature
        ,baton->signature_field
);

  int result = git_commit_create_with_signature(
baton->out,baton->repo,baton->commit_content,baton->signature,baton->signature_field    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::CreateWithSignatureWorker::HandleOKCallback() {
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
        err = Nan::Error("Method createWithSignature has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("commit_content"));
      workerArguments.push(GetFromPersistent("signature"));
      workerArguments.push(GetFromPersistent("signature_field"));
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
        v8::Local<v8::Object> err = Nan::Error("Method createWithSignature has thrown an error.")->ToObject();
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
     * @param Commit callback
   */
NAN_METHOD(GitCommit::Dup) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DupBaton* baton = new DupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->source = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[0]));
  DupWorker *worker = new DupWorker(baton, callback);
  worker->SaveToPersistent("source", info.This());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::DupWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->source
);

  int result = git_commit_dup(
&baton->out,baton->source    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::DupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitCommit baton->out
       to = GitCommit::New(baton->out, true  );
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
NAN_METHOD(GitCommit::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

git_commit_free(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
  
/*
    * @param String field
    * @param Buf callback
   */
NAN_METHOD(GitCommit::HeaderField) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String field is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  HeaderFieldBaton* baton = new HeaderFieldBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

        baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->asize = 0;
  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_field = NULL;

  String::Utf8Value field(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_field = (const char *) malloc(field.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_field, *field, field.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_field) + field.length()), 0, 1);
// end convert_from_v8 block
  baton->field = from_field;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  HeaderFieldWorker *worker = new HeaderFieldWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("field", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::HeaderFieldWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->out
        ,baton->commit
        ,baton->field
);

  int result = git_commit_header_field(
baton->out,baton->commit,baton->field    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::HeaderFieldWorker::HandleOKCallback() {
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
        err = Nan::Error("Method headerField has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("field"));
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
        v8::Local<v8::Object> err = Nan::Error("Method headerField has thrown an error.")->ToObject();
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
     * @return Oid  result    */
NAN_METHOD(GitCommit::Id) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const git_oid * result = git_commit_id(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
   * @param Oid id
    * @param Commit callback
   */
NAN_METHOD(GitCommit::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
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
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::LookupWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->id
);

  int result = git_commit_lookup(
&baton->commit,baton->repo,baton->id    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->commit != NULL) {
    // GitCommit baton->commit
       to = GitCommit::New(baton->commit, true  );
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
      workerArguments.push(GetFromPersistent("id"));
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid id
   * @param Number len
    * @param Commit callback
   */
NAN_METHOD(GitCommit::LookupPrefix) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupPrefixBaton* baton = new LookupPrefixBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();
// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->len = from_len;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[3]));
  LookupPrefixWorker *worker = new LookupPrefixWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("len", info[2]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::LookupPrefixWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->repo
        ,baton->id
);

  int result = git_commit_lookup_prefix(
&baton->commit,baton->repo,baton->id,baton->len    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::LookupPrefixWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->commit != NULL) {
    // GitCommit baton->commit
       to = GitCommit::New(baton->commit, true  );
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
        err = Nan::Error("Method lookupPrefix has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("id"));
      workerArguments.push(GetFromPersistent("len"));
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
        v8::Local<v8::Object> err = Nan::Error("Method lookupPrefix has thrown an error.")->ToObject();
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::Message) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_message(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
     * @return String  result    */
NAN_METHOD(GitCommit::MessageEncoding) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_message_encoding(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
     * @return String  result    */
NAN_METHOD(GitCommit::MessageRaw) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_message_raw(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
    * @param Number n
    * @param Commit callback
   */
NAN_METHOD(GitCommit::NthGenAncestor) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NthGenAncestorBaton* baton = new NthGenAncestorBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->n = from_n;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  NthGenAncestorWorker *worker = new NthGenAncestorWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("n", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::NthGenAncestorWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->commit
);

  int result = git_commit_nth_gen_ancestor(
&baton->ancestor,baton->commit,baton->n    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::NthGenAncestorWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->ancestor != NULL) {
    // GitCommit baton->ancestor
       to = GitCommit::New(baton->ancestor, true  );
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
        err = Nan::Error("Method nthGenAncestor has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("n"));
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
        v8::Local<v8::Object> err = Nan::Error("Method nthGenAncestor has thrown an error.")->ToObject();
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
     * @return Repository  result    */
NAN_METHOD(GitCommit::Owner) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    git_repository * result = git_commit_owner(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
    * @param Number n
    * @param Commit callback
   */
NAN_METHOD(GitCommit::Parent) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ParentBaton* baton = new ParentBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->n = from_n;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  ParentWorker *worker = new ParentWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("n", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCommit::ParentWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->commit
);

  int result = git_commit_parent(
&baton->out,baton->commit,baton->n    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCommit::ParentWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitCommit baton->out
       to = GitCommit::New(baton->out, true  );
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
        err = Nan::Error("Method parent has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("n"));
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
        v8::Local<v8::Object> err = Nan::Error("Method parent has thrown an error.")->ToObject();
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
   * @param Number n
     * @return Oid  result    */
NAN_METHOD(GitCommit::ParentId) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const git_oid * result = git_commit_parent_id(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
,  from_n
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
     * @return Number  result    */
NAN_METHOD(GitCommit::Parentcount) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    unsigned int result = git_commit_parentcount(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
NAN_METHOD(GitCommit::RawHeader) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_raw_header(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
     * @return String  result    */
NAN_METHOD(GitCommit::Summary) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const char * result = git_commit_summary(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
NAN_METHOD(GitCommit::Time) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    git_time_t result = git_commit_time(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
NAN_METHOD(GitCommit::TimeOffset) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    int result = git_commit_time_offset(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Tree tree_out
       * @return Number  result    */
NAN_METHOD(GitCommit::Tree) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Tree tree_out is required.");
  }

// start convert_from_v8 block
  git_tree ** from_tree_out = NULL;
*from_tree_out = Nan::ObjectWrap::Unwrap<GitTree>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_tree_out
        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    int result = git_commit_tree(
  from_tree_out
,  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitCommit::TreeId) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
);

    const git_oid * result = git_commit_tree_id(
  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCommitTraits>;
 