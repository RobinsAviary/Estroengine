#pragma once

namespace Estro {
	template <typename T>
	struct Rectangle {
		T x = 0;
		T y = 0;
		T w = 0;
		T h = 0;
		Rectangle(T xPosition = 0, T yPosition = 0, T width = 0, T height = 0);
	};

	template <typename T>
	struct Vector2 {
		T x = 0;
		T y = 0;

		Vector2(T xPosition, T yPosition) {
			x = xPosition;
			y = yPosition;
		}

		Vector2<T> yx();

		Vector2<T> operator+ (const Vector2<T>& rhs);
		Vector2<T> operator- (const Vector2<T>& rhs);
		Vector2<T> operator* (const Vector2<T>& rhs);
		Vector2<T> operator/ (const Vector2<T>& rhs);

		void operator+=(Vector2<T>& rhs);
		void operator-=(Vector2<T>& rhs);
		void operator*=(Vector2<T>& rhs);
		void operator/=(Vector2<T>& rhs);
		bool operator==(const Vector2<T>& rhs);
		bool operator!=(const Vector2<T>& rhs);

		template <typename newType>
		Vector2<newType> cast();

		bool isInside(Rectangle<T> rectangle);
	};

	template <typename T>
	struct Vector3 {
		public:
			T x = 0;
			T y = 0;
			T z = 0;
			
			Vector3(T xPosition = 0, T yPosition = 0, T zPosition = 0);
			Vector3(Vector2<T> vector = { 0, 0 });

			Vector3<T> yxz();
			Vector3<T> zxy();
			Vector3<T> xzy();
			Vector3<T> yzx();
			Vector3<T> zyx();
			Vector2<T> xy();
			Vector2<T> yx();

			Vector3<T> operator+ (const Vector3<T>& rhs);
			Vector3<T> operator- (const Vector3<T>& rhs);
			Vector3<T> operator* (const Vector3<T>& rhs);
			Vector3<T> operator/ (const Vector3<T>& rhs);

			void operator+=(Vector3<T>& rhs);
			void operator-=(Vector3<T>& rhs);
			void operator*=(Vector3<T>& rhs);
			void operator/=(Vector3<T>& rhs);
			bool operator==(const Vector3<T>& rhs);
			bool operator!=(const Vector3<T>& rhs);

			template <typename newType>
			Vector3<newType> cast();
	};
}