package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.RemoteException;
import android.util.Log;

public interface IMcuService extends android.os.IInterface {
	/** Local-side IPC implementation stub class. */
	public static abstract class Stub extends android.os.Binder implements
			android.zhonghong.mcuservice.IMcuService {
		private static final java.lang.String DESCRIPTOR = "android.zhonghong.IMcuService";

		/** Construct the stub at attach it to the interface. */
		public Stub() {
			this.attachInterface(this, DESCRIPTOR);
		}

		/**
		 * Cast an IBinder object into an android.zhonghong.IMcuService
		 * interface, generating a proxy if needed.
		 */
		public static android.zhonghong.mcuservice.IMcuService asInterface(
				android.os.IBinder obj) {
			if ((obj == null)) {
				return null;
			}
			android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
			if (((iin != null) && (iin instanceof android.zhonghong.mcuservice.IMcuService))) {
				return ((android.zhonghong.mcuservice.IMcuService) iin);
			}
			return new android.zhonghong.mcuservice.IMcuService.Stub.Proxy(obj);
		}

		@Override
		public android.os.IBinder asBinder() {
			return this;
		}

		@Override
		public boolean onTransact(int code, android.os.Parcel data,
				android.os.Parcel reply, int flags)
				throws android.os.RemoteException {
			switch (code) {
			case INTERFACE_TRANSACTION: {
				reply.writeString(DESCRIPTOR);
				return true;
			}
			case TRANSACTION_GET_TEST: {
				// done in c++ server
				data.enforceInterface(DESCRIPTOR);
				int _result = this.getTest();
				reply.writeNoException();
				reply.writeInt(_result);
				return true;
			}
			case TRANSACTION_OBTAIN_INFO: {
				// done in c++ server
				data.enforceInterface(DESCRIPTOR);
				int domain = data.readInt();
				int cmd = data.readInt();
				Parcel out = Parcel.obtain();
				boolean _result = this.obtainInfo(domain, cmd, out);
//				reply.writeNoException();
				if(out != null && out.dataSize() > 0)
				{
					reply.appendFrom(out, 0, out.dataSize());
				}
				reply.writeInt(_result?1:0);
				return true;
			}
			case TRANSACTION_SEND_INFO: {
				// done in c++ server
				data.enforceInterface(DESCRIPTOR);
				int domain = data.readInt();
				int cmd = data.readInt();
				Parcel in = Parcel.obtain();
				if(data.dataAvail() > 0)
				{
					in.appendFrom(data, data.dataPosition(), data.dataSize()-data.dataPosition());
					in.setDataPosition(0);
				}
				boolean _result = this.sendInfo(domain, cmd, in);
//				reply.writeNoException();
				reply.writeInt(_result?1:0);
				return true;
			}
			case TRANSACTION_REGIST_DATA_CHANGED_LISTENER: {
				// done in c++ server
				data.enforceInterface(DESCRIPTOR);
				int domain = data.readInt();
				IDataChangedListener listener = IDataChangedListener.Stub.asInterface(data.readStrongBinder());
				int _result = this.registDataChangedListener(domain, listener);
//				reply.writeNoException();
				reply.writeInt(_result);
				return true;
			}
			case TRANSACTION_UNREGIST_DATA_CHANGED_LISTENER: {
				// done in c++ server
				data.enforceInterface(DESCRIPTOR);
				int domain = data.readInt();
				IDataChangedListener listener = IDataChangedListener.Stub.asInterface(data.readStrongBinder());
				int _result = this.unregistDataChangedListener(domain, listener);
//				reply.writeNoException();
				reply.writeInt(_result);
				return true;
			}
			}
			return super.onTransact(code, data, reply, flags);
		}

		private static class Proxy implements android.zhonghong.mcuservice.IMcuService {
			private static final String TAG = "McuServiceClient";
			private android.os.IBinder mRemote;

			Proxy(android.os.IBinder remote) {
				mRemote = remote;
			}

			@Override
			public android.os.IBinder asBinder() {
				return mRemote;
			}

			public java.lang.String getInterfaceDescriptor() {
				return DESCRIPTOR;
			}

			@Override
			public int getTest() throws android.os.RemoteException {
				android.os.Parcel _data = android.os.Parcel.obtain();
				android.os.Parcel _reply = android.os.Parcel.obtain();
				int _result;
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					mRemote.transact(Stub.TRANSACTION_GET_TEST, _data, _reply, 0);
//					_reply.readException();
					_result = _reply.readInt();
				} finally {
					_reply.recycle();
					_data.recycle();
				}
				return _result;
			}

			@Override
			public boolean obtainInfo(int domain, int cmd, Parcel out)
					throws RemoteException {
				// TODO Auto-generated method stub
				android.os.Parcel _data = android.os.Parcel.obtain();
				android.os.Parcel _reply = android.os.Parcel.obtain();
				boolean _result;
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					_data.writeInt(domain);
					_data.writeInt(cmd);
					mRemote.transact(Stub.TRANSACTION_OBTAIN_INFO, _data, _reply, 0);
//					_reply.readException();
					//4 bytes result flag at last, 
					if (_reply != null && _reply.dataSize() > 4) {
						out.appendFrom(_reply, 0, _reply.dataSize()-4);
						out.setDataPosition(0);
					}
					_reply.setDataPosition(_reply.dataSize()-4);
					_result = (_reply.readInt() == 1);
				} finally {
					_reply.recycle();
					_data.recycle();
				}
				if(!_result) Log.e(TAG, "an error occurred when obtainInfo domain="+domain+",cmd="+cmd);
				return _result;
			}

			@Override
			public boolean sendInfo(int domain, int cmd, Parcel in)
					throws RemoteException {
				// TODO Auto-generated method stub
				android.os.Parcel _data = android.os.Parcel.obtain();
				android.os.Parcel _reply = android.os.Parcel.obtain();
				boolean _result;
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					_data.writeInt(domain);
					_data.writeInt(cmd);
					if (in != null && in.dataSize() > 0) {
						_data.appendFrom(in, 0, in.dataSize());;
					}
					mRemote.transact(Stub.TRANSACTION_SEND_INFO, _data, _reply, 0);
//					_reply.readException();
					_result = (_reply.readInt() == 1);
				} finally {
					_reply.recycle();
					_data.recycle();
				}
				return _result;
			}

			@Override
			public int registDataChangedListener(int domain, IDataChangedListener listener)
					throws RemoteException {
				// TODO Auto-generated method stub
				android.os.Parcel _data = android.os.Parcel.obtain();
				android.os.Parcel _reply = android.os.Parcel.obtain();
				int _result;
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					_data.writeInt(domain);
					_data.writeStrongBinder((((listener != null)) ? (listener
							.asBinder()) : (null)));
					mRemote.transact(Stub.TRANSACTION_REGIST_DATA_CHANGED_LISTENER, _data, _reply, 0);
//					_reply.readException();
					_result = _reply.readInt();
					Log.i(TAG, "registDataChangedListener address = "+listener.hashCode()+", result="+_result);
				} finally {
					_reply.recycle();
					_data.recycle();
				}
				return _result;
			}

			@Override
			public int unregistDataChangedListener(int domain,
					IDataChangedListener listener) throws RemoteException {
				// TODO Auto-generated method stub
				android.os.Parcel _data = android.os.Parcel.obtain();
				android.os.Parcel _reply = android.os.Parcel.obtain();
				int _result;
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					_data.writeInt(domain);
					_data.writeStrongBinder((((listener != null)) ? (listener
							.asBinder()) : (null)));
					mRemote.transact(Stub.TRANSACTION_UNREGIST_DATA_CHANGED_LISTENER, _data, _reply, 0);
//					_reply.readException();
					_result = _reply.readInt();
					Log.i(TAG, "unregistDataChangedListener address = "+listener.hashCode()+", result="+_result);
				} finally {
					_reply.recycle();
					_data.recycle();
				}
				return _result;
			}
		}

		static final int TRANSACTION_GET_TEST = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
		static final int TRANSACTION_OBTAIN_INFO = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
		static final int TRANSACTION_SEND_INFO = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
		static final int TRANSACTION_REGIST_DATA_CHANGED_LISTENER = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
		static final int TRANSACTION_UNREGIST_DATA_CHANGED_LISTENER = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
	}

	public int getTest() throws android.os.RemoteException;
	public boolean obtainInfo(int domain, int cmd, Parcel out) throws android.os.RemoteException;
	public boolean sendInfo(int domain, int cmd, Parcel in) throws android.os.RemoteException;
	public int registDataChangedListener(int domain, IDataChangedListener listener) throws android.os.RemoteException;
	public int unregistDataChangedListener(int domain, IDataChangedListener listener) throws android.os.RemoteException;
}
