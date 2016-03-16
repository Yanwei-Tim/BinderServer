/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_DATACHANGEDLISTENER_H
#define ANDROID_DATACHANGEDLISTENER_H

#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#include "IDataChangedListener.h"

/**
* �̳�����࣬��дnotify����������RadioProxy��registRadioInfoChanagedListener����
* ��������ʵ�����õ�����ˣ�����˼�����ݱ仯�ͻ�ص�notify������
* Ӧ����Ҫ��дnotify������ ʵ���Լ��Ĺ���
*/

namespace android {

class DataChangedListener: public BnDataChangedListener
{
public:
	
	DataChangedListener();
  	virtual ~DataChangedListener();
	//callback method
    virtual void notify(int msg, int ext0, int ext1, const Parcel *obj);
};

}; // namespace android

#endif // ANDROID_DATACHANGEDLISTENER_H


