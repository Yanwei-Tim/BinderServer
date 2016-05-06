package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.util.Log;

import android.zhonghong.mcuservice.Constant;

public interface IDataChangedListener extends android.os.IInterface {
	/** Local-side IPC implementation stub class. */
	public static abstract class Stub extends android.os.Binder implements
			android.zhonghong.mcuservice.IDataChangedListener {
		// DO NOT MODIFY
		private static final java.lang.String DESCRIPTOR = "android.zhonghong.IDataChangedListener";
		private static final String TAG = "leo";

		/** Construct the stub at attach it to the interface. */
		public Stub() {
			this.attachInterface(this, DESCRIPTOR);
		}

		/**
		 * Cast an IBinder object into an
		 * android.zhonghong.IRadioInfoChangedListener interface, generating a
		 * proxy if needed.
		 */
		public static android.zhonghong.mcuservice.IDataChangedListener asInterface(
				android.os.IBinder obj) {
			if ((obj == null)) {
				return null;
			}
			android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
			if (((iin != null) && (iin instanceof android.zhonghong.mcuservice.IDataChangedListener))) {
				return ((android.zhonghong.mcuservice.IDataChangedListener) iin);
			}
			return new android.zhonghong.mcuservice.IDataChangedListener.Stub.Proxy(obj);
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
			// it sets oneway flag , so service do not wait this result.
			case TRANSACTION_notify: {
				data.enforceInterface(DESCRIPTOR);
				int msg = data.readInt();
				int ext0 = data.readInt();
				int ext1 = data.readInt();
				Parcel p = null;
				if (data.dataAvail() > 0) {
					p = Parcel.obtain();
					p.appendFrom(data, data.dataPosition(), data.dataSize()
							- data.dataPosition());
					p.setDataPosition(0);
				}
				Constant.LOGB("notify:msg="+msg+", ext0="+ext0+", ext1="+ext1);
				this.notify(msg, ext0, ext1, p);
				return true;
			}
			}
			return super.onTransact(code, data, reply, flags);
		}

		private static class Proxy implements
				android.zhonghong.mcuservice.IDataChangedListener {
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
			public void notify(int msg, int ext0, int ext1, Parcel parcel)
					throws android.os.RemoteException {
				// done in c++
				android.os.Parcel _data = android.os.Parcel.obtain();
				try {
					_data.writeInterfaceToken(DESCRIPTOR);
					_data.writeInt(msg);
					_data.writeInt(ext0);
					_data.writeInt(ext1);
					if (parcel != null && parcel.dataSize() > 0) {
						_data.appendFrom(parcel, 0, parcel.dataSize());
					}
					mRemote.transact(Stub.TRANSACTION_notify, _data, null,
							android.os.IBinder.FLAG_ONEWAY);
				} finally {
					_data.recycle();
				}
			}
		}

		static final int TRANSACTION_notify = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
	}

	public void notify(int msg, int ext0, int ext1, Parcel parcel)
			throws android.os.RemoteException;
}
