// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/cred.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCred::~GitCred() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                       }

  void GitCred::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Cred").ToLocalChecked());

           Nan::SetMethod(tpl, "defaultNew", DefaultNew);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "hasUsername", HasUsername);
             Nan::SetMethod(tpl, "sshKeyFromAgent", SshKeyFromAgent);
             Nan::SetMethod(tpl, "sshKeyMemoryNew", SshKeyMemoryNew);
             Nan::SetMethod(tpl, "sshKeyNew", SshKeyNew);
             Nan::SetMethod(tpl, "usernameNew", UsernameNew);
             Nan::SetMethod(tpl, "userpassPlaintextNew", UserpassPlaintextNew);
    
    InitializeTemplate(tpl);

    v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Cred").ToLocalChecked(), _constructor_template);
  }

  
/*
    * @return Cred out    */
NAN_METHOD(GitCred::DefaultNew) {
  Nan::EscapableHandleScope scope;

  git_cred * out = 0;
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

git_cred_default_new(
&  out
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New(out, false  );
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
NAN_METHOD(GitCred::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue() != NULL) {
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue()
);

git_cred_free(
  Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue()
    );

    Nan::ObjectWrap::Unwrap<GitCred>(info.This())->ClearValue();
  }
     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitCred::HasUsername) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue()
);

    int result = git_cred_has_username(
  Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue()
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
  * @param String username
     * @return Cred out    */
NAN_METHOD(GitCred::SshKeyFromAgent) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username = NULL;

  String::Utf8Value username(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_username = (const char *) malloc(username.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_username, *username, username.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_username) + username.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_username
);

git_cred_ssh_key_from_agent(
&  out
,  from_username
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New(out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param String username
   * @param String publickey
   * @param String privatekey
   * @param String passphrase
    * @param Cred callback
   */
NAN_METHOD(GitCred::SshKeyMemoryNew) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String publickey is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String privatekey is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String passphrase is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SshKeyMemoryNewBaton* baton = new SshKeyMemoryNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_username = NULL;

  String::Utf8Value username(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_username = (const char *) malloc(username.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_username, *username, username.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_username) + username.length()), 0, 1);
// end convert_from_v8 block
  baton->username = from_username;
// start convert_from_v8 block
  const char * from_publickey = NULL;

  String::Utf8Value publickey(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_publickey = (const char *) malloc(publickey.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_publickey, *publickey, publickey.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_publickey) + publickey.length()), 0, 1);
// end convert_from_v8 block
  baton->publickey = from_publickey;
// start convert_from_v8 block
  const char * from_privatekey = NULL;

  String::Utf8Value privatekey(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_privatekey = (const char *) malloc(privatekey.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_privatekey, *privatekey, privatekey.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_privatekey) + privatekey.length()), 0, 1);
// end convert_from_v8 block
  baton->privatekey = from_privatekey;
// start convert_from_v8 block
  const char * from_passphrase = NULL;

  String::Utf8Value passphrase(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_passphrase = (const char *) malloc(passphrase.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_passphrase, *passphrase, passphrase.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_passphrase) + passphrase.length()), 0, 1);
// end convert_from_v8 block
  baton->passphrase = from_passphrase;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[4]));
  SshKeyMemoryNewWorker *worker = new SshKeyMemoryNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("username", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("publickey", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("privatekey", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("passphrase", info[3]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCred::SshKeyMemoryNewWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->username
        ,baton->publickey
        ,baton->privatekey
        ,baton->passphrase
);

  int result = git_cred_ssh_key_memory_new(
&baton->out,baton->username,baton->publickey,baton->privatekey,baton->passphrase    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCred::SshKeyMemoryNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitCred baton->out
       to = GitCred::New(baton->out, false  );
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
        err = Nan::Error("Method sshKeyMemoryNew has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("username"));
      workerArguments.push(GetFromPersistent("publickey"));
      workerArguments.push(GetFromPersistent("privatekey"));
      workerArguments.push(GetFromPersistent("passphrase"));
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
        v8::Local<v8::Object> err = Nan::Error("Method sshKeyMemoryNew has thrown an error.")->ToObject();
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
  * @param String username
   * @param String publickey
   * @param String privatekey
   * @param String passphrase
     * @return Cred out    */
NAN_METHOD(GitCred::SshKeyNew) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String publickey is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String privatekey is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String passphrase is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username = NULL;

  String::Utf8Value username(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_username = (const char *) malloc(username.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_username, *username, username.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_username) + username.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_publickey = NULL;

  String::Utf8Value publickey(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_publickey = (const char *) malloc(publickey.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_publickey, *publickey, publickey.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_publickey) + publickey.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_privatekey = NULL;

  String::Utf8Value privatekey(info[2]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_privatekey = (const char *) malloc(privatekey.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_privatekey, *privatekey, privatekey.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_privatekey) + privatekey.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_passphrase = NULL;

  String::Utf8Value passphrase(info[3]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_passphrase = (const char *) malloc(passphrase.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_passphrase, *passphrase, passphrase.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_passphrase) + passphrase.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_username
        ,    from_publickey
        ,    from_privatekey
        ,    from_passphrase
);

git_cred_ssh_key_new(
&  out
,  from_username
,  from_publickey
,  from_privatekey
,  from_passphrase
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New(out, false  );
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
  
/*
  * @param String username
    * @param Cred callback
   */
NAN_METHOD(GitCred::UsernameNew) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  UsernameNewBaton* baton = new UsernameNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_username = NULL;

  String::Utf8Value username(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_username = (const char *) malloc(username.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_username, *username, username.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_username) + username.length()), 0, 1);
// end convert_from_v8 block
  baton->username = from_username;

  Nan::Callback *callback = new Nan::Callback(v8::Local<Function>::Cast(info[1]));
  UsernameNewWorker *worker = new UsernameNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("username", info[0]->ToObject());

  AsyncLibgit2QueueWorker(worker);
  return;
}

void GitCred::UsernameNewWorker::Execute() {
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */true        ,baton->username
);

  int result = git_cred_username_new(
&baton->cred,baton->username    );

    baton->error_code = result;

    if (result != GIT_OK && giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

  }
}

void GitCred::UsernameNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->cred != NULL) {
    // GitCred baton->cred
       to = GitCred::New(baton->cred, false  );
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
        err = Nan::Error("Method usernameNew has thrown an error.")->ToObject();
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
      workerArguments.push(GetFromPersistent("username"));
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
        v8::Local<v8::Object> err = Nan::Error("Method usernameNew has thrown an error.")->ToObject();
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
  * @param String username
   * @param String password
     * @return Cred out    */
NAN_METHOD(GitCred::UserpassPlaintextNew) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String password is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username = NULL;

  String::Utf8Value username(info[0]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_username = (const char *) malloc(username.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_username, *username, username.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_username) + username.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_password = NULL;

  String::Utf8Value password(info[1]->ToString());
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_password = (const char *) malloc(password.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_password, *password, password.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_password) + password.length()), 0, 1);
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_username
        ,    from_password
);

git_cred_userpass_plaintext_new(
&  out
,  from_username
,  from_password
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New(out, false  );
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
template class NodeGitWrapper<GitCredTraits>;
 