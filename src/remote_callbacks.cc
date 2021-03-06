// This is a generated file, modify: generate/templates/templates/struct_content.cc

#include <nan.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/remote_callbacks.h"
#include "nodegit_wrapper.cc"

  #include "../include/cred.h"
  #include "../include/cert.h"
  #include "../include/transfer_progress.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitRemoteCallbacks::GitRemoteCallbacks() : NodeGitWrapper<GitRemoteCallbacksTraits>(NULL, true, v8::Local<v8::Object>())
{
        git_remote_callbacks wrappedValue = GIT_REMOTE_CALLBACKS_INIT;
      this->raw = (git_remote_callbacks*) malloc(sizeof(git_remote_callbacks));
      memcpy(this->raw, &wrappedValue, sizeof(git_remote_callbacks));
  
  this->ConstructFields();
}

GitRemoteCallbacks::GitRemoteCallbacks(git_remote_callbacks* raw, bool selfFreeing, v8::Local<v8::Object> owner)
 : NodeGitWrapper<GitRemoteCallbacksTraits>(raw, selfFreeing, owner)
{
  this->ConstructFields();
}

GitRemoteCallbacks::~GitRemoteCallbacks() {
             if (this->credentials.HasCallback()) {
               this->raw->payload = NULL;
           }
             if (this->certificate_check.HasCallback()) {
               this->raw->payload = NULL;
           }
             if (this->transfer_progress.HasCallback()) {
               this->raw->payload = NULL;
           }
       }

void GitRemoteCallbacks::ConstructFields() {
   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->credentials = NULL;
             this->raw->payload = (void *)this;
    
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->certificate_check = NULL;
             this->raw->payload = (void *)this;
    
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->transfer_progress = NULL;
             this->raw->payload = (void *)this;
    
          v8::Local<Value> payload = Nan::Undefined();
          this->payload.Reset(payload);
    }

void GitRemoteCallbacks::InitializeComponent(v8::Local<v8::Object> target) {
  Nan::HandleScope scope;

  v8::Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("RemoteCallbacks").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("credentials").ToLocalChecked(), GetCredentials, SetCredentials);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("certificateCheck").ToLocalChecked(), GetCertificateCheck, SetCertificateCheck);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("transferProgress").ToLocalChecked(), GetTransferProgress, SetTransferProgress);
     
  InitializeTemplate(tpl);

  v8::Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("RemoteCallbacks").ToLocalChecked(), _constructor_template);
}

    NAN_GETTER(GitRemoteCallbacks::GetVersion) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitRemoteCallbacks::SetVersion) {
      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRemoteCallbacks::GetCredentials) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->credentials.HasCallback()) {
          info.GetReturnValue().Set(wrapper->credentials.GetCallback()->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetCredentials) {
      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        Nan::Callback *callback = NULL;
        int throttle = 0;
        bool waitForResult = true;

        if (value->IsFunction()) {
          callback = new Nan::Callback(value.As<Function>());
        } else if (value->IsObject()) {
          v8::Local<Object> object = value.As<Object>();
          v8::Local<String> callbackKey;
          Nan::MaybeLocal<Value> maybeObjectCallback = Nan::Get(object, Nan::New("callback").ToLocalChecked());
          if (!maybeObjectCallback.IsEmpty()) {
            v8::Local<Value> objectCallback = maybeObjectCallback.ToLocalChecked();
            if (objectCallback->IsFunction()) {
              callback = new Nan::Callback(objectCallback.As<Function>());

              Nan::MaybeLocal<Value> maybeObjectThrottle = Nan::Get(object, Nan::New("throttle").ToLocalChecked());
              if(!maybeObjectThrottle.IsEmpty()) {
                v8::Local<Value> objectThrottle = maybeObjectThrottle.ToLocalChecked();
                if (objectThrottle->IsNumber()) {
                  throttle = (int)objectThrottle.As<Number>()->Value();
                }
              }

              Nan::MaybeLocal<Value> maybeObjectWaitForResult = Nan::Get(object, Nan::New("waitForResult").ToLocalChecked());
              if(!maybeObjectWaitForResult.IsEmpty()) {
                Local<Value> objectWaitForResult = maybeObjectWaitForResult.ToLocalChecked();
                waitForResult = (bool)objectWaitForResult->BooleanValue();
              }
            }
          }
        }
        if (callback) {
          if (!wrapper->raw->credentials) {
            wrapper->raw->credentials = (git_cred_acquire_cb)credentials_cppCallback;
          }

          wrapper->credentials.SetCallback(callback, throttle, waitForResult);
        }

     }

      GitRemoteCallbacks* GitRemoteCallbacks::credentials_getInstanceFromBaton(CredentialsBaton* baton) {
           return static_cast<GitRemoteCallbacks*>(baton->
                  payload
  );
       }
      
      int GitRemoteCallbacks::credentials_cppCallback (
          git_cred ** cred,           const char * url,           const char * username_from_url,           unsigned int allowed_types,           void * payload        ) {
        CredentialsBaton *baton =
          new CredentialsBaton(1);

          baton->cred = cred;
          baton->url = url;
          baton->username_from_url = username_from_url;
          baton->allowed_types = allowed_types;
          baton->payload = payload;
 
        GitRemoteCallbacks* instance = credentials_getInstanceFromBaton(baton);
        
           int result;

          if (instance->credentials.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->credentials.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(credentials_async);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(credentials_async, deleteBaton);
          }
          return result;
       }
      

      void GitRemoteCallbacks::credentials_async(void *untypedBaton) {
        Nan::HandleScope scope;

        CredentialsBaton* baton = static_cast<CredentialsBaton*>(untypedBaton);
        GitRemoteCallbacks* instance = credentials_getInstanceFromBaton(baton);

        if (instance->credentials.GetCallback()->IsEmpty()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               if (baton->url == NULL) {
                  baton->url = "";
              }
                if (baton->username_from_url == NULL) {
                  baton->username_from_url = "";
              }
                 v8::Local<Value> argv[4] = {
                     Nan::New(baton->url).ToLocalChecked(),
                    Nan::New(baton->username_from_url).ToLocalChecked(),
                     Nan::New(baton->allowed_types),
                  Nan::New(instance->payload)
             };
 
        Nan::TryCatch tryCatch;

            v8::Local<v8::Value> result = instance->credentials.GetCallback()->Call(4, argv);
 
        if(PromiseCompletion::ForwardIfPromise(result, baton, GitRemoteCallbacks::credentials_promiseCompleted)) {
          return;
        }
        
             if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
              GitCred* wrapper = Nan::ObjectWrap::Unwrap<GitCred>(result->ToObject());
              wrapper->selfFreeing = false;

              *baton->cred = wrapper->GetValue();
              baton->result = 0;
             }
            else {
              baton->result = baton->defaultResult;
            }
           baton->Done();
       }

      void GitRemoteCallbacks::credentials_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
        Nan::HandleScope scope;

        CredentialsBaton* baton = static_cast<CredentialsBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsEmpty() || result->IsNativeError()) {
                baton->result = -1;
              }
              else if (!result->IsNull() && !result->IsUndefined()) {
                GitCred* wrapper = Nan::ObjectWrap::Unwrap<GitCred>(result->ToObject());
                wrapper->selfFreeing = false;

                *baton->cred = wrapper->GetValue();
                baton->result = 0;
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->    payload  );
             v8::Local<v8::Object> parent = instance->handle();
            SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

            baton->result = -1;
          }
          baton->Done();
       }
      NAN_GETTER(GitRemoteCallbacks::GetCertificateCheck) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->certificate_check.HasCallback()) {
          info.GetReturnValue().Set(wrapper->certificate_check.GetCallback()->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetCertificateCheck) {
      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        Nan::Callback *callback = NULL;
        int throttle = 0;
        bool waitForResult = true;

        if (value->IsFunction()) {
          callback = new Nan::Callback(value.As<Function>());
        } else if (value->IsObject()) {
          v8::Local<Object> object = value.As<Object>();
          v8::Local<String> callbackKey;
          Nan::MaybeLocal<Value> maybeObjectCallback = Nan::Get(object, Nan::New("callback").ToLocalChecked());
          if (!maybeObjectCallback.IsEmpty()) {
            v8::Local<Value> objectCallback = maybeObjectCallback.ToLocalChecked();
            if (objectCallback->IsFunction()) {
              callback = new Nan::Callback(objectCallback.As<Function>());

              Nan::MaybeLocal<Value> maybeObjectThrottle = Nan::Get(object, Nan::New("throttle").ToLocalChecked());
              if(!maybeObjectThrottle.IsEmpty()) {
                v8::Local<Value> objectThrottle = maybeObjectThrottle.ToLocalChecked();
                if (objectThrottle->IsNumber()) {
                  throttle = (int)objectThrottle.As<Number>()->Value();
                }
              }

              Nan::MaybeLocal<Value> maybeObjectWaitForResult = Nan::Get(object, Nan::New("waitForResult").ToLocalChecked());
              if(!maybeObjectWaitForResult.IsEmpty()) {
                Local<Value> objectWaitForResult = maybeObjectWaitForResult.ToLocalChecked();
                waitForResult = (bool)objectWaitForResult->BooleanValue();
              }
            }
          }
        }
        if (callback) {
          if (!wrapper->raw->certificate_check) {
            wrapper->raw->certificate_check = (git_transport_certificate_check_cb)certificate_check_cppCallback;
          }

          wrapper->certificate_check.SetCallback(callback, throttle, waitForResult);
        }

     }

      GitRemoteCallbacks* GitRemoteCallbacks::certificate_check_getInstanceFromBaton(CertificateCheckBaton* baton) {
           return static_cast<GitRemoteCallbacks*>(baton->
                 payload
  );
       }
      
      int GitRemoteCallbacks::certificate_check_cppCallback (
          git_cert * cert,           int valid,           const char * host,           void * payload        ) {
        CertificateCheckBaton *baton =
          new CertificateCheckBaton(1);

          baton->cert = cert;
          baton->valid = valid;
          baton->host = host;
          baton->payload = payload;
 
        GitRemoteCallbacks* instance = certificate_check_getInstanceFromBaton(baton);
        
           int result;

          if (instance->certificate_check.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->certificate_check.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(certificate_check_async);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(certificate_check_async, deleteBaton);
          }
          return result;
       }
      

      void GitRemoteCallbacks::certificate_check_async(void *untypedBaton) {
        Nan::HandleScope scope;

        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(untypedBaton);
        GitRemoteCallbacks* instance = certificate_check_getInstanceFromBaton(baton);

        if (instance->certificate_check.GetCallback()->IsEmpty()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

                  if (baton->host == NULL) {
                  baton->host = "";
              }
               v8::Local<Value> argv[4] = {
                  GitCert::New(baton->cert, false),
                     Nan::New(baton->valid),
                    Nan::New(baton->host).ToLocalChecked(),
                  Nan::New(instance->payload)
             };
 
        Nan::TryCatch tryCatch;

            v8::Local<v8::Value> result = instance->certificate_check.GetCallback()->Call(4, argv);
 
        if(PromiseCompletion::ForwardIfPromise(result, baton, GitRemoteCallbacks::certificate_check_promiseCompleted)) {
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

      void GitRemoteCallbacks::certificate_check_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
        Nan::HandleScope scope;

        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsEmpty() || result->IsNativeError()) {
                baton->result = -1;
              }
              else if (!result->IsNull() && !result->IsUndefined()) {
                 if (result->IsNumber()) {
                  baton->result = (int)result->ToNumber()->Value();
                }
                else{
                  baton->result = baton->defaultResult;
                }
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton->   payload  );
             v8::Local<v8::Object> parent = instance->handle();
            SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

            baton->result = -1;
          }
          baton->Done();
       }
      NAN_GETTER(GitRemoteCallbacks::GetTransferProgress) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        if (wrapper->transfer_progress.HasCallback()) {
          info.GetReturnValue().Set(wrapper->transfer_progress.GetCallback()->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitRemoteCallbacks::SetTransferProgress) {
      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        Nan::Callback *callback = NULL;
        int throttle = 100;
        bool waitForResult = true;

        if (value->IsFunction()) {
          callback = new Nan::Callback(value.As<Function>());
        } else if (value->IsObject()) {
          v8::Local<Object> object = value.As<Object>();
          v8::Local<String> callbackKey;
          Nan::MaybeLocal<Value> maybeObjectCallback = Nan::Get(object, Nan::New("callback").ToLocalChecked());
          if (!maybeObjectCallback.IsEmpty()) {
            v8::Local<Value> objectCallback = maybeObjectCallback.ToLocalChecked();
            if (objectCallback->IsFunction()) {
              callback = new Nan::Callback(objectCallback.As<Function>());

              Nan::MaybeLocal<Value> maybeObjectThrottle = Nan::Get(object, Nan::New("throttle").ToLocalChecked());
              if(!maybeObjectThrottle.IsEmpty()) {
                v8::Local<Value> objectThrottle = maybeObjectThrottle.ToLocalChecked();
                if (objectThrottle->IsNumber()) {
                  throttle = (int)objectThrottle.As<Number>()->Value();
                }
              }

              Nan::MaybeLocal<Value> maybeObjectWaitForResult = Nan::Get(object, Nan::New("waitForResult").ToLocalChecked());
              if(!maybeObjectWaitForResult.IsEmpty()) {
                Local<Value> objectWaitForResult = maybeObjectWaitForResult.ToLocalChecked();
                waitForResult = (bool)objectWaitForResult->BooleanValue();
              }
            }
          }
        }
        if (callback) {
          if (!wrapper->raw->transfer_progress) {
            wrapper->raw->transfer_progress = (git_transfer_progress_cb)transfer_progress_cppCallback;
          }

          wrapper->transfer_progress.SetCallback(callback, throttle, waitForResult);
        }

     }

      GitRemoteCallbacks* GitRemoteCallbacks::transfer_progress_getInstanceFromBaton(TransferProgressBaton* baton) {
           return static_cast<GitRemoteCallbacks*>(baton->
               payload
  );
       }
      
      int GitRemoteCallbacks::transfer_progress_cppCallback (
          const git_transfer_progress * stats,           void * payload        ) {
        TransferProgressBaton *baton =
          new TransferProgressBaton(0);

          baton->stats = stats;
          baton->payload = payload;
 
        GitRemoteCallbacks* instance = transfer_progress_getInstanceFromBaton(baton);
        
           int result;

          if (instance->transfer_progress.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->transfer_progress.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(transfer_progress_async);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(transfer_progress_async, deleteBaton);
          }
          return result;
       }
      

      void GitRemoteCallbacks::transfer_progress_async(void *untypedBaton) {
        Nan::HandleScope scope;

        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(untypedBaton);
        GitRemoteCallbacks* instance = transfer_progress_getInstanceFromBaton(baton);

        if (instance->transfer_progress.GetCallback()->IsEmpty()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               v8::Local<Value> argv[2] = {
                  GitTransferProgress::New(baton->stats, false),
                  Nan::New(instance->payload)
             };
 
        Nan::TryCatch tryCatch;

            v8::Local<v8::Value> result = instance->transfer_progress.GetCallback()->Call(2, argv);
 
        if(PromiseCompletion::ForwardIfPromise(result, baton, GitRemoteCallbacks::transfer_progress_promiseCompleted)) {
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

      void GitRemoteCallbacks::transfer_progress_promiseCompleted(bool isFulfilled, AsyncBaton *_baton, v8::Local<v8::Value> result) {
        Nan::HandleScope scope;

        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsEmpty() || result->IsNativeError()) {
                baton->result = -1;
              }
              else if (!result->IsNull() && !result->IsUndefined()) {
                 if (result->IsNumber()) {
                  baton->result = (int)result->ToNumber()->Value();
                }
                else{
                  baton->result = baton->defaultResult;
                }
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               GitRemoteCallbacks* instance = static_cast<GitRemoteCallbacks*>(baton-> payload  );
             v8::Local<v8::Object> parent = instance->handle();
            SetPrivate(parent, Nan::New("NodeGitPromiseError").ToLocalChecked(), result);

            baton->result = -1;
          }
          baton->Done();
       }
      NAN_GETTER(GitRemoteCallbacks::GetPayload) {

      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->payload));

     }

    NAN_SETTER(GitRemoteCallbacks::SetPayload) {
      GitRemoteCallbacks *wrapper = Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(info.This());

        wrapper->payload.Reset(value);

     }

   
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRemoteCallbacksTraits>;
