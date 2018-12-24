#ifndef KNU_MATHLIBRARY6_HPP
#define KNU_MATHLIBRARY6_HPP

#include <array>
#include <iostream>
#include <vector>
#include <numeric>

namespace knu {
	namespace math {
		inline namespace v1 {

			template<typename T>
			const T KNU_EPSILON = static_cast<T>(0.000001);

			// Helper utility functions
			template<typename T>
			const T KNU_PI = static_cast<T>(3.141592653);

			template<typename T>
			const T KNU_DEGREES_TO_RADIANS_CONSTANT = static_cast<T>(3.141592653) / 180;

			template<typename T>
			const T KNU_RADIANS_TO_DEGREES_CONSTANT = 180 / static_cast<T>(3.141592653);

			struct vector_component_2 {};
			struct vector_component_3 {};
			struct vector_component_4 {};

			// matrix size constants
			const int MAT_2_2 = 4;
			const int MAT_3_3 = 9;
			const int MAT_4_4 = 16;

			template<typename T>
			struct vec2
			{
			public:

				using value_type = T;
				using component_count = vector_component_2;

				// Default constructor
				vec2()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0))
				{}

				vec2(T ptr[2])
					:
					x(ptr[0]),
					y(ptr[1])
				{}

				vec2(T x_, T y_)
					:
					x(x_),
					y(y_)
				{}

				// Copy constructor
				vec2(const vec2 &v)
					:
					x(v.x),
					y(v.y)
				{}
				
				// move constructor
				vec2(vec2 &&v) :
					x(v.x),
					y(v.y)
				{
					std::cout << "rvalue reference called\n";
				}

				vec2 &operator =(const vec2 &v)
				{
					x = v.x;
					y = v.y;

					return (*this);
				}

				vec2 &operator =(vec2 &&v)
				{
					x = v.x;
					y = v.y;

					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);

					std::cout << "move assignment operator called\n";

					return (*this);
				}

				bool operator ==(const vec2 &v) const
				{
					return ((abs(x - v.x) <= KNU_EPSILON<T>) &&
						(abs(y - v.y) <= KNU_EPSILON<T>));
				}

				vec2 operator +(const vec2 &v) const
				{
					return (vec2(x + v.x, y + v.y));

				}

				vec2 &operator +=(const vec2 &v)
				{
					x += v.x;
					y += v.y;

					return (*this);
				}

				vec2<T> operator -(const vec2 &v)const
				{
					return (vec2(x - v.x, y - v.y));
				}

				vec2<T> &operator -=(const vec2 &v)
				{
					x -= v.x;
					y -= v.y;

					return (*this);
				}


				vec2 operator *(T scalar)const
				{
					return (vec2(x * scalar, y * scalar));
				}

				vec2 &operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;

					return (*this);
				}

				vec2 operator /(T scalar)const
				{
					return (vec2<T>(x / scalar, y / scalar));
				}

				vec2 &operator /=(T scalar)
				{
					x /= scalar;
					y /= scalar;

					return (*this);
				}

				float length()const
				{
					return (sqrt((x * x) + (y * y)));
				}

				float length_squared()const
				{
					return ((x * x) + (y * y));
				}

				vec2& normalize()
				{
					if (is_zero())
						return (*this);

					T length_ = length();

					x /= length_;
					y /= length_;

					return (*this);
				}

				bool is_zero()const
				{
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) && 
						((y - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				T dot(const vec2 &v)const
				{
					return ((x * v.x) + (y * v.y));
				}

				void zero()
				{
					x = y = static_cast<T>(0);
				}

				void set(T x_, T y_)
				{
					x = x_;
					y = y_;
				}

				T x, y;
			};			// Class Vec2

			template<typename T>
			class vec3 {
			public:

				using value_type = T;
				using component_count = vector_component_3;

				// Default constructor
				vec3()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0)),
					z(static_cast<T>(0))
				{}

				vec3<T>(T x_, T y_, T z_)
					:
					x(x_),
					y(y_),
					z(z_)
				{}

				// Destructor
				~vec3() {}

				// Copy constructor
				vec3<T>(const vec3 &v)
					:
					x(v.x),
					y(v.y),
					z(v.z)
				{}

				// move constructor
				vec3(vec3 &&v) :
					x(v.x),
					y(v.y),
					z(v.z)
				{
					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);
					v.z = static_cast<T>(0);
					std::cout << "rvalue reference called\n";
				}

				vec3<T> operator -()const
				{
					return vec3<T>(-x, -y, -z);
				}

				vec3<T> &operator =(const vec3 &v)
				{
					x = v.x;
					y = v.y;
					z = v.z;

					return (*this);
				}

				vec3 &operator =(const vec3 &&v)
				{
					x = v.x;
					y = v.y;
					z = v.z;

					std::cout << "V3f move assignment operator called\n";
					return (*this);
				}

				bool operator ==(const vec3 &v) const
				{
					return ((abs(x - v.x) <= KNU_EPSILON<T>) &&
						(abs(y - v.y) <= KNU_EPSILON<T>) &&
						(abs(z - v.z) <= KNU_EPSILON<T>));
				}

				const vec3 operator +(const vec3 &v)const
				{
					return (vec3(x + v.x, y + v.y, z + v.z));
				}

	
				vec3& operator +=(const vec3 &v)
				{
					x += v.x;
					y += v.y;
					z += v.z;

					return (*this);
				}

	
				const vec3 operator -(const vec3 &v)const
				{
					return (vec3(x - v.x, y - v.y, z - v.z));
				}

				vec3 &operator -=(const vec3 &v)
				{
					x -= v.x;
					y -= v.y;
					z -= v.z;

					return (*this);
				}

				const vec3 operator *(T scalar)const
				{
					return (vec3(x * scalar, y * scalar, z * scalar));
				}

				vec3& operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;
					z *= scalar;

					return (*this);
				}

				const vec3 operator /(T scalar)const
				{
					return (vec3(x / scalar, y / scalar, z / scalar));
				}

				vec3& operator /=(T scalar)
				{
					x /= scalar;
					y /= scalar;
					z /= scalar;

					return (*this);
				}

				T length()const
				{
					return (sqrt((x * x) + (y * y) + (z * z)));
				}

				T length_squared()const
				{
					return ((x * x) + (y * y) + (z * z));
				}

				vec3& normalize()
				{
					if (is_zero())
						return (*this);

					T length_ = length();
					x /= length_;
					y /= length_;
					z /= length_;

					return (*this);
				}

				bool is_zero()const
				{
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((y - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((z - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				T dot(const vec3 &v)const
				{
					return ((x * v.x) + (y * v.y) + (z * v.z));
				}

				vec3<T> cross(const vec3 &v)const
				{
					return (vec3(((y * v.z) - (z * v.y)), ((z * v.x) - (x * v.z)), ((x * v.y) - (y * v.x))));
				}

				void zero()
				{
					x = y = z = static_cast<T>(0);
				}

				void set(T x_, T y_, T z_)
				{
					x = x_;
					y = y_;
					z = z_;
				}

				vec2<T> get_vec2() const
				{
					return vec2<T>(x, y);
				}

				T x, y, z;

			};			// Class Vec3

			template<typename T>
			class vec4 {
			public:

				using value_type = T;
				using component_count = vector_component_4;

				// Default constructor
				vec4<T>()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0)),
					z(static_cast<T>(0)),
					w(static_cast<T>(1))
				{}

				vec4(T x_, T y_, T z_, T w_)
					:
					x(x_),
					y(y_),
					z(z_),
					w(w_)
				{}

				vec4<T>(const vec3<T> &v, T w_)
					:
					x(v.x),
					y(v.y),
					z(v.z),
					w(w_)
				{}

				// Copy constructor
				vec4<T>(const vec4<T> &v)
					:
					x(v.x),
					y(v.y),
					z(v.z),
					w(v.w)
				{}

				// move constructor
				vec4(vec4 &&v) :
					x(v.x),
					y(v.y),
					z(v.z),
					w(v.w)
				{
					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);
					v.z = static_cast<T>(0);
					v.w = static_cast<T>(0);
					std::cout << "rvalue reference called for v4\n";
				}

				vec4<T> operator -()const
				{
					return vec4(-x, -y, -z, -w);
				}

				vec4& operator =(const vec4 &v)
				{
					x = v.x;
					y = v.y;
					z = v.z;
					w = v.w;

					return (*this);
				}

				vec4 &operator =(const vec4 &&v)
				{
					x = v.x;
					y = v.y;
					z = v.z;
					w = v.w;

					std::cout << "V4f move assignment operator called\n";
					return (*this);
				}

				bool operator ==(const vec4 &v) const
				{
					return ((abs(x - v.x) <= KNU_EPSILON<T>) &&
						(abs(y - v.y) <= KNU_EPSILON<T>) &&
						(abs(z - v.z) <= KNU_EPSILON<T>) &&
						(abs(w - v.w) <= KNU_EPSILON<T>));
				}

				vec4 operator +(const vec4 &v)const
				{
					return (vec4(x + v.x, y + v.y, z + v.z, w + v.w));
				}

				vec4& operator +=(const vec4 &v)
				{
					x += v.x;
					y += v.y;
					z += v.z;
					w += v.w;

					return (*this);
				}

				vec4 operator -(const vec4 &v)const
				{
					return (vec4(x - v.x, y - v.y, z - v.z, w - v.w));
				}

				vec4& operator -=(const vec4 &v)
				{
					x -= v.x;
					y -= v.y;
					z -= v.z;
					w -= v.w;

					return (*this);
				}

				vec4 operator *(T scalar)const
				{
					return (vec4(x * scalar, y * scalar, z * scalar, w * scalar));
				}

				vec4& operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;
					z *= scalar;
					w *= scalar;

					return (*this);
				}

				vec4 operator /(T scalar)const
				{
					return (vec4(x / scalar, y / scalar, z / scalar, w / scalar));
				}

				vec4& operator /=(T scalar)
				{
					x /= scalar;
					y /= scalar;
					z /= scalar;
					w /= scalar;

					return (*this);
				}

				T length()const
				{
					return (sqrt((x * x) + (y * y) + (z * z))); // removed w as it shouldn't contribute to length
				}

				T length_squared()const
				{
					return ((x * x) + (y * y) + (z * z));   // removed w as it shouldn't contribute to length_squared
				}

				vec4<T>& normalize()
				{
					if (is_zero())
						return (*this);

					T length_ = length();

					x /= length_;
					y /= length_;
					z /= length_;
					// w /= length_;    // doesn't need to be normalized

					return (*this);
				}

				bool is_zero()const
				{
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((y - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((z - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((w - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				T dot(const vec4 &v)const
				{
					return ((x * v.x) + (y * v.y) + (z * v.z) + (w * v.w));
				}

				void zero()
				{
					x = y = z = w = static_cast<T>(0);
				}

				void set(T x_, T y_, T z_, T w_)
				{
					x = x_;
					y = y_;
					z = z_;
					w = w_;
				}

				vec3<T> get_vec3() const
				{
					return vec3<T>(x, y, z);
				}

				T x, y, z, w;
			};

			template<typename T>
			struct  mat2
			{
				using value_type = T;

				mat2<T>() :
					elements()
				{
					set_identity();
				}

				// column major
				mat2(T a, T b, T c, T d) :
					elements()
				{
					elements[0] = a;
					elements[1] = b;
					elements[2] = c;
					elements[3] = d;
				}

				mat2(const mat2 &m) :
					elements()
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
				}

				mat2 &operator=(const mat2 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
					return *this;
				}

				bool operator==(const mat2 &m) const
				{
					bool are_equal = std::equal(std::begin(elements), std::end(elements),
						std::begin(m.elements),
						[](auto e1, auto e2) -> bool {
						return abs(e1 - e2) <= KNU_EPSILON<T>;
					});

					return are_equal;
				}

				// column major
				T &operator [](int i)
				{
					return elements[i];
				}

				T operator [](int i)const
				{
					return elements[i];
				}

				vec2<T> get_row_0()const
				{
					return vec2<T>(elements[0], elements[2]);
				}

				vec2<T> get_row_1()const
				{
					return vec2<T>(elements[1], elements[3]);
				}

				void set_row_0(T a, T b)
				{
					elements[0] = a;
					elements[2] = b;
				}

				void set_row_0(const vec2<T> &v)
				{
					set_row_0(v.x, v.y);
				}

				void set_row_1(T a, T b)
				{
					elements[1] = a;
					elements[3] = b;
				}

				void set_row_1(const vec2<T> &v)
				{
					set_row_1(v.x, v.y);
				}

				vec2<T> get_column_0()const
				{
					return vec2<T>(elements[0], elements[1]);
				}

				vec2<T> get_column_1()const
				{
					return vec2<T>(elements[2], elements[3]);
				}

				void set_column_0(T a, T b)
				{
					elements[0] = a;
					elements[1] = b;
				}

				void set_column_0(const vec2<T> &v)
				{
					set_column_0(v.x, v.y);
				}

				void set_column_1(T a, T b)
				{
					elements[2] = a;
					elements[3] = b;
				}

				void set_column_1(const vec2<T> &v)
				{
					set_column_1(v.x, v.y);
				}

				mat2 &set_identity()
				{
					set_row_0(1, 0);
					set_row_1(0, 1);
					return *this;
				}

				mat2 &zero()
				{
					std::fill(std::begin(elements), std::end(elements),
						static_cast<T>(0));
					return *this;
				}

				mat2 operator+(const mat2 &m)const
				{
					return mat2(elements[0] + m.elements[0],
						elements[1] + m.elements[1],
						elements[2] + m.elements[2],
						elements[3] + m.elements[3]);
				}

				mat2 &operator+=(const mat2 &m)
				{
					*this = *this + m;
					return *this;
				}

				mat2 operator-(const mat2 &m)const
				{
					return mat2(elements[0] - m.elements[0],
						elements[1] - m.elements[1],
						elements[2] - m.elements[2],
						elements[3] - m.elements[3]);
				}

				mat2 &operator-=(const mat2 &m)
				{
					*this = *this - m;
					return *this;
				}

				mat2 operator*(const mat2 &m)const
				{
					mat2 ret;
					ret[0] = get_row_0().dot(m.get_column_0());
					ret[2] = get_row_0().dot(m.get_column_1());

					ret[1] = get_row_1().dot(m.get_column_0());
					ret[3] = get_row_1().dot(m.get_column_1());
					return ret;
				}

				mat2 &scale(T x, T y)
				{
					set_row_0(x, 0);
					set_row_1(0, y);
					return *this;
				}
				mat2 &transpose()
				{
					auto row0 = get_row_0();
					auto row1 = get_row_1();
					set_column_0(row0);
					set_column_1(row1);

					return *this;
				}

				mat2 &rotation_z(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, -s);
					set_row_1(s, c);
					return *this;
				}

				T* data()
				{
					return &elements[0];
				}

				std::array<T, MAT_2_2> elements;
			};	// Mat2

			template<typename T>
			struct mat3
			{
			public:
				using value_type = T;

				mat3():elements()
				{
					set_identity();
				}

				mat3(T a, T b, T c, T d, T e, T f, T g, T h, T i)
				{
					elements[0] = a;
					elements[1] = b;
					elements[2] = c;
					elements[3] = d;
					elements[4] = e;
					elements[5] = f;
					elements[6] = g;
					elements[7] = h;
					elements[8] = i;
				}

				mat3(const mat3 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
				}

				mat3 &operator=(const mat3 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
					return *this;
				}

				bool operator==(const mat3 &m) const
				{
					bool are_equal = std::equal(std::begin(elements), std::end(elements),
						std::begin(m.elements),
						[](auto e1, auto e2) -> bool {
						return abs(e1 - e2) <= KNU_EPSILON<T>;
					});

					return are_equal;
				}

				T &operator [](int i)
				{
					return elements[i];
				}

				const T &operator [](int i)const
				{
					return elements[i];
				}

				vec3<T> get_row_0()const
				{
					return vec3<T>(elements[0], elements[3], elements[6]);
				}

				vec3<T> get_row_1()const
				{
					return vec3<T>(elements[1], elements[4], elements[7]);
				}

				vec3<T> get_row_2()const
				{
					return vec3<T>(elements[2], elements[5], elements[8]);
				}

				void set_row_0(T x, T y, T z)
				{
					elements[0] = x;
					elements[3] = y;
					elements[6] = z;
				}

				void set_row_0(const vec3<T> &v)
				{
					set_row_0(v.x, v.y, v.z);
				}

				void set_row_1(T x, T y, T z)
				{
					elements[1] = x;
					elements[4] = y;
					elements[7] = z;
				}

				void set_row_1(const vec3<T> &v)
				{
					set_row_1(v.x, v.y, v.z);
				}

				void set_row_2(T x, T y, T z)
				{
					elements[2] = x;
					elements[5] = y;
					elements[8] = z;
				}

				void set_row_2(const vec3<T> &v)
				{
					set_row_2(v.x, v.y, v.z);
				}

				vec3<T> get_column_0()const
				{
					return vec3<T>(elements[0], elements[1], elements[2]);
				}

				vec3<T> get_column_1()const
				{
					return vec3<T>(elements[3], elements[4], elements[5]);
				}

				vec3<T> get_column_2()const
				{
					return vec3<T>(elements[6], elements[7], elements[8]);
				}

				void set_column_0(T x, T y, T z)
				{
					elements[0] = x;
					elements[1] = y;
					elements[2] = z;
				}

				void set_column_0(const vec3<T> &v)
				{
					set_column_0(v.x, v.y, v.z);
				}

				void set_column_1(T x, T y, T z)
				{
					elements[3] = x;
					elements[4] = y;
					elements[5] = z;
				}

				void set_column_1(const vec3<T> &v)
				{
					set_column_1(v.x, v.y, v.z);
				}

				void set_column_2(T x, T y, T z)
				{
					elements[6] = x;
					elements[7] = y;
					elements[8] = z;
				}

				void set_column_2(const vec3<T> &v)
				{
					set_column_2(v.x, v.y, v.z);
				}

				mat3 operator+(const mat3 &m)const
				{
					mat3 ret(elements[0] + m.elements[0],
						elements[1] + m.elements[1],
						elements[2] + m.elements[2],
						elements[3] + m.elements[3],
						elements[4] + m.elements[4],
						elements[5] + m.elements[5],
						elements[6] + m.elements[6],
						elements[7] + m.elements[7],
						elements[8] + m.elements[8]);
					return ret;
				}

				mat3 &operator +=(const mat3 &m)
				{
					*this = *this + m;
					return *this;
				}

				mat3 operator-(const mat3 &m)const
				{
					mat3<T> ret(elements[0] - m.elements[0],
						elements[1] - m.elements[1],
						elements[2] - m.elements[2],
						elements[3] - m.elements[3],
						elements[4] - m.elements[4],
						elements[5] - m.elements[5],
						elements[6] - m.elements[6],
						elements[7] - m.elements[7],
						elements[8] - m.elements[8]);
					return ret;
				}

				mat3 &operator -=(const mat3 &m)
				{
					*this = *this - m;
					return *this;
				}

				mat3 operator*(const mat3 &m)const
				{
					mat3<T> ret;
					ret[0] = get_row_0().dot(m.get_column_0());
					ret[3] = get_row_0().dot(m.get_column_1());
					ret[6] = get_row_0().dot(m.get_column_2());

					ret[1] = get_row_1().dot(m.get_column_0());
					ret[4] = get_row_1().dot(m.get_column_1());
					ret[7] = get_row_1().dot(m.get_column_2());

					ret[2] = get_row_2().dot(m.get_column_0());
					ret[5] = get_row_2().dot(m.get_column_1());
					ret[8] = get_row_2().dot(m.get_column_2());

					return ret;
				}

				mat3 &operator*=(const mat3 &m)
				{
					*this = *this * m;
					return *this;
				}

				mat3 &set_identity()
				{
					set_column_0(1, 0, 0);
					set_column_1(0, 1, 0);
					set_column_2(0, 0, 1);

					return *this;
				}

				bool is_identity() const
				{
					vec3<T> r0 = { 1, 0, 0 };
					vec3<T> r1 = { 0, 1, 0 };
					vec3<T> r2 = { 0, 0, 1 };

					return get_row_0() == r0 &&
						get_row_1() == r1 &&
						get_row_2() == r2;
				}

				mat3 &zero()
				{
					std::fill(std::begin(elements), std::end(elements),
						static_cast<T>(0));
					return *this;
				}

				mat3 &scale(T x, T y, T z)
				{
					set_row_0(x, 0, 0);
					set_row_1(0, y, 0);
					set_row_2(0, 0, z);
					return *this;
				}

				mat3 &transpose()
				{
					auto row0 = get_row_0();
					auto row1 = get_row_1();
					auto row2 = get_row_2();

					set_column_0(row0);
					set_column_1(row1);
					set_column_2(row2);

					return *this;
				}

				mat3 &rotation_x(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(1, 0, 0);
					set_row_1(0, c, s);
					set_row_2(0, -s, c);

					return *this;
				}

				mat3 &rotation_y(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, 0, -s);
					set_row_1(0, 1, 0);
					set_row_2(s, 0, c);

					return *this;
				}

				mat3 &rotation_z(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, -s, 0);
					set_row_1(s, c, 0);
					set_row_2(0, 0, 1);

					return *this;
				}

				T* data()
				{
					return &elements[0];
				}

			public:
				std::array<T, MAT_3_3> elements;
			}; // mat3

			template<typename T>
			struct mat4
			{
			public:
				using value_type = T;

				mat4():elements()
				{
					set_identity();
				}

				mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p)
				{
					elements[0] = a;
					elements[1] = b;
					elements[2] = c;
					elements[3] = d;
					elements[4] = e;
					elements[5] = f;
					elements[6] = g;
					elements[7] = h;
					elements[8] = i;
					elements[9] = j;
					elements[10] = k;
					elements[11] = l;
					elements[12] = m;
					elements[13] = n;
					elements[14] = o;
					elements[15] = p;
				}

				mat4(const mat4 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
				}

				mat4(mat4 &&m):
					elements(std::move(m.elements))
				{
					std::cout << "MATRIX4 MOVE CONSTRUCTOR CALLED\n";
					//std::copy(std::begin(m.elements), std::end(m.elements),
					//	std::begin(elements));
				}

				mat4 &operator=(const mat4 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
					return *this;
				}

				mat4 &operator=(mat4 &&m)
				{
					elements = std::move(m.elements);
					std::cout << "MATRIX4 MOVE ASSIGNMENT CALLED\n";
					return *this;
				}

				bool operator==(const mat4 &m) const
				{
					bool are_equal = std::equal(std::begin(elements), std::end(elements),
						std::begin(m.elements),
						[](auto e1, auto e2) -> bool {
						return abs(e1 - e2) <= KNU_EPSILON<T>;
					});

					return are_equal;
				}

				T &operator [](int i)
				{
					return elements[i];
				}

				const T &operator [](int i)const
				{
					return elements[i];
				}

				vec4<T> get_row_0()const
				{
					return vec4<T>(elements[0], elements[4], elements[8], elements[12]);
				}

				vec4<T> get_row_1()const
				{
					return vec4<T>(elements[1], elements[5], elements[9], elements[13]);
				}

				vec4<T> get_row_2()const
				{
					return vec4<T>(elements[2], elements[6], elements[10], elements[14]);
				}

				vec4<T> get_row_3()const
				{
					return vec4<T>(elements[3], elements[7], elements[11], elements[15]);
				}

				void set_row_0(T x, T y, T z, T w)
				{
					elements[0] = x;
					elements[4] = y;
					elements[8] = z;
					elements[12] = w;
				}


				void set_row_0(const vec4<T> &v)
				{
					set_row_0(v.x, v.y, v.z, v.w);
				}

				void set_row_1(T x, T y, T z, T w)
				{
					elements[1] = x;
					elements[5] = y;
					elements[9] = z;
					elements[13] = w;
				}

				void set_row_1(const vec4<T> &v)
				{
					set_row_1(v.x, v.y, v.z, v.w);
				}

				void set_row_2(T x, T y, T z, T w)
				{
					elements[2] = x;
					elements[6] = y;
					elements[10] = z;
					elements[14] = w;
				}

				void set_row_2(const vec4<T> &v)
				{
					set_row_2(v.x, v.y, v.z, v.w);
				}

				void set_row_3(T x, T y, T z, T w)
				{
					elements[3] = x;
					elements[7] = y;
					elements[11] = z;
					elements[15] = w;
				}

				void set_row_3(const vec4<T> &v)
				{
					set_row_3(v.x, v.y, v.z, v.w);
				}

				vec4<T> get_column_0()const
				{
					return vec4<T>(elements[0], elements[1], elements[2], elements[3]);
				}

				vec4<T> get_column_1()const
				{
					return vec4<T>(elements[4], elements[5], elements[6], elements[7]);
				}

				vec4<T> get_column_2()const
				{
					return vec4<T>(elements[8], elements[9], elements[10], elements[11]);
				}

				vec4<T> get_column_3()const
				{
					return vec4<T>(elements[12], elements[13], elements[14], elements[15]);
				}

				void set_column_0(T x, T y, T z, T w)
				{
					elements[0] = x;
					elements[1] = y;
					elements[2] = z;
					elements[3] = w;
				}

				void set_column_0(const vec4<T> &v)
				{
					set_column_0(v.x, v.y, v.z, v.w);
				}

				void set_column_1(T x, T y, T z, T w)
				{
					elements[4] = x;
					elements[5] = y;
					elements[6] = z;
					elements[7] = w;
				}

				void set_column_1(const vec4<T> &v)
				{
					set_column_1(v.x, v.y, v.z, v.w);
				}

				void set_column_2(T x, T y, T z, T w)
				{
					elements[8] = x;
					elements[9] = y;
					elements[10] = z;
					elements[11] = w;
				}

				void set_column_2(const vec4<T> &v)
				{
					set_column_2(v.x, v.y, v.z, v.w);
				}

				void set_column_3(T x, T y, T z, T w)
				{
					elements[12] = x;
					elements[13] = y;
					elements[14] = z;
					elements[15] = w;
				}

				void set_column_3(const vec4<T> &v)
				{
					set_column_3(v.x, v.y, v.z, v.w);
				}

				mat4<T> operator+(const mat4<T> &m)const
				{
					mat4<T> ret(elements[0] + m.elements[0],
						elements[1] + m.elements[1],
						elements[2] + m.elements[2],
						elements[3] + m.elements[3],
						elements[4] + m.elements[4],
						elements[5] + m.elements[5],
						elements[6] + m.elements[6],
						elements[7] + m.elements[7],
						elements[8] + m.elements[8],
						elements[9] + m.elements[9],
						elements[10] + m.elements[10],
						elements[11] + m.elements[11],
						elements[12] + m.elements[12],
						elements[13] + m.elements[13],
						elements[14] + m.elements[14],
						elements[15] + m.elements[15]);

					return ret;
				}

				mat4 &operator +=(const mat4 &m)
				{
					*this = *this + m;
					return *this;
				}

				mat4 operator-(const mat4 &m)const
				{
					mat4 ret(elements[0] - m.elements[0],
						elements[1] - m.elements[1],
						elements[2] - m.elements[2],
						elements[3] - m.elements[3],
						elements[4] - m.elements[4],
						elements[5] - m.elements[5],
						elements[6] - m.elements[6],
						elements[7] - m.elements[7],
						elements[8] - m.elements[8],
						elements[9] - m.elements[9],
						elements[10] - m.elements[10],
						elements[11] - m.elements[11],
						elements[12] - m.elements[12],
						elements[13] - m.elements[13],
						elements[14] - m.elements[14],
						elements[15] - m.elements[15]);

					return ret;
				}

				template<typename T2>
				mat4<T> &operator -=(const mat4<T2> &m)
				{
					*this = *this - m;
					return *this;
				}

				mat4<T> operator*(double scalar)const
				{
					mat4<T> ret;

					std::transform(std::begin(elements), std::end(elements), std::begin(ret.elements),
						[=](T val) {
						return (scalar * val);
					});
					return ret;
				}


				mat4 operator*(const mat4 &m)const
				{
					mat4<T> ret;

					ret[0] = get_row_0().dot(m.get_column_0());
					ret[4] = get_row_0().dot(m.get_column_1());
					ret[8] = get_row_0().dot(m.get_column_2());
					ret[12] = get_row_0().dot(m.get_column_3());

					ret[1] = get_row_1().dot(m.get_column_0());
					ret[5] = get_row_1().dot(m.get_column_1());
					ret[9] = get_row_1().dot(m.get_column_2());
					ret[13] = get_row_1().dot(m.get_column_3());

					ret[2] = get_row_2().dot(m.get_column_0());
					ret[6] = get_row_2().dot(m.get_column_1());
					ret[10] = get_row_2().dot(m.get_column_2());
					ret[14] = get_row_2().dot(m.get_column_3());

					ret[3] = get_row_3().dot(m.get_column_0());
					ret[7] = get_row_3().dot(m.get_column_1());
					ret[11] = get_row_3().dot(m.get_column_2());
					ret[15] = get_row_3().dot(m.get_column_3());

					return ret;
				}

				template<typename T2>
				mat4<T> &operator*=(const mat4<T2> &m)
				{
					*this = *this * m;
					return *this;
				}

				mat4<T>& translate(T x, T y, T z)
				{
					set_column_0(vec4<T>(T(1.0f), T(0.0f), T(0.0f), T(0.0f)));
					set_column_1(vec4<T>(T(0.0f), T(1.0f), T(0.0f), T(0.0f)));
					set_column_2(vec4<T>(T(0.0f), T(0.0f), T(1.0f), T(0.0f)));
					set_column_3(vec4<T>(x, y, z, T(1.0f)));

					return *this;
				}

				mat4 &translate(const vec4<T> &v)
				{
					translate(v.x, v.y, v.z);
					return *this;
				}

				mat4 &rotation_x(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(1, 0, 0, 0);
					set_row_1(0, c, s, 0);
					set_row_2(0, -s, c, 0);
					set_row_3(0, 0, 0, 1);

					return *this;
				}

				mat4 &rotation_y(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, 0, -s, 0);
					set_row_1(0, 1, 0, 0);
					set_row_2(s, 0, c, 0);
					set_row_3(0, 0, 0, 1);

					return *this;
				}

				mat4 &rotation_z(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, -s, 0, 0);
					set_row_1(s, c, 0, 0);
					set_row_2(0, 0, 1, 0);
					set_row_3(0, 0, 0, 1);

					return *this;
				}

				mat4 &scale(T x, T y, T z)
				{
					set_row_0(x, 0, 0, 0);
					set_row_1(0, y, 0, 0);
					set_row_2(0, 0, z, 0);
					set_row_3(0, 0, 0, 1);

					return *this;
				}

				mat4 &transpose()
				{
					auto row0 = get_row_0();
					auto row1 = get_row_1();
					auto row2 = get_row_2();
					auto row3 = get_row_3();

					set_column_0(row0);
					set_column_1(row1);
					set_column_2(row2);
					set_column_3(row3);

					return *this;
				}

				mat4 &set_identity()
				{
					set_row_0(1, 0, 0, 0);
					set_row_1(0, 1, 0, 0);
					set_row_2(0, 0, 1, 0);
					set_row_3(0, 0, 0, 1);

					return *this;
				}

				bool is_identity() const
				{
					vec4<T> r0 = { 1, 0, 0, 0 };
					vec4<T> r1 = { 0, 1, 0, 0 };
					vec4<T> r2 = { 0, 0, 1, 0 };
					vec4<T> r3 = { 0, 0, 0, 1 };


					return get_row_0() == r0 &&
						get_row_1() == r1 &&
						get_row_2() == r2 &&
						get_row_3() == r3;
				}

				mat4 &zero()
				{
					std::fill(std::begin(elements), std::end(elements), 0);
					return *this;
				}

				mat3<T> make_3x3()const
				{
					mat3<T> m;
					vec4<T> v;

					v = get_row_0();
					m.set_row_0(v.x, v.y, v.z);

					v = get_row_1();
					m.set_row_1(v.x, v.y, v.z);

					v = get_row_2();
					m.set_row_2(v.x, v.y, v.z);

					return m;
				}

				T* data()
				{
					return &elements[0];
				}

			public:
				std::array<T, MAT_4_4> elements;
			};	// Matrix4

			// Math math non member functions
			template<typename T>
			vec2<T> operator *(const mat2<T> &m, const vec2<T> &v)
			{
				vec2<T> ret;
				ret.x = m.get_row_0().dot(v);
				ret.y = m.get_row_1().dot(v);
				return ret;

			}

			template<typename T>
			vec3<T> operator*(const mat3<T> &m, const vec3<T> &v)
			{
				vec3<T> ret;
				ret.x = m.get_row_0().dot(v);
				ret.y = m.get_row_1().dot(v);
				ret.z = m.get_row_2().dot(v);

				return ret;
			}

			// for now, only supporting matrix post-multiplication
			// so matrix * vector
			template<typename T>
			vec4<T> operator*(const mat4<T> &m, const vec4<T> &v)
			{
				vec4<T> ret;
				ret.x = m.get_row_0().dot(v);
				ret.y = m.get_row_1().dot(v);
				ret.z = m.get_row_2().dot(v);
				ret.w = m.get_row_3().dot(v);

				return ret;
			}

			template<typename T>
			T degrees_to_radians(T degrees)
			{
				return (KNU_PI<T> * degrees) / static_cast<T>(180.0);
			}

			template<typename T>
			T radians_to_degrees(T radians)
			{
				return (radians * KNU_RADIANS_TO_DEGREES_CONSTANT<T>);
			}

			template<typename T>
			mat4<T> make_rotation_x(T radians)
			{
				mat4<T> m;
				m.rotation_x(radians);
				return m;
			}

			template<typename T>
			mat4<T> make_rotation_y(T radians)
			{
				mat4<T> m;
				m.rotation_y(radians);
				return m;
			}

			template<typename T>
			mat4<T> make_rotation_z(T radians)
			{
				mat4<T> m;
				m.rotation_z(radians);
				return m;
			}

			template<typename T>
			mat4<T> make_scale(T x, T y, T z)
			{
				mat4<T> m;
				m.scale(x, y, z);
				return m;
			}

			template<typename T>
			mat4<T> make_translate(T x, T y, T z)
			{
				mat4<T> m;
				m.translate(x, y, z);
				return m;
			}

			// some utility functions
			template<typename Point, typename Scalar>
			Point affine_combination(const std::vector<Point> &p, const std::vector<Scalar> &s)
			{
				static_assert(std::is_same<typename Point::value_type, Scalar>::value,
					"The underlying type of Point is not the same type as Scalar");

				std::vector<Point> r(p.size());

				std::transform(std::begin(p), std::end(p), std::begin(s), std::begin(r),
					[](const Point &p_, const Scalar &s_)->Point
				{
					return p_ * s_;
				});

				return std::accumulate(std::begin(r), std::end(r), Point());
			}

		} // namespace of v1

		using vector2f = vec2<float>;
		using vector2d = vec2<double>;
		using vector2i = vec2<std::int32_t>;
		using vector2l = vec2<std::int64_t>;

		using vector3f = vec3<float>;
		using vector3d = vec3<double>;
		using vector3i = vec3<std::int32_t>;
		using vector3l = vec3<std::int64_t>;

		using vector4f = vec4<float>;
		using vector4d = vec4<double>;
		using vector4i = vec4<std::int32_t>;
		using vector4l = vec4<std::int64_t>;

		using matrix2f = mat2<float>;
		using matrix2d = mat2<double>;
		using matrix2i = mat2<std::int32_t>;
		using matrix2l = mat2<std::int64_t>;

		using matrix3f = mat3<float>;
		using matrix3d = mat3<double>;
		using matrix3i = mat3<std::int32_t>;
		using matrix3l = mat3<std::int64_t>;

		using matrix4f = mat4<float>;
		using matrix4d = mat4<double>;
		using matrix4i = mat4<std::int32_t>;
		using matrix4l = mat4<std::int64_t>;

	} // namespace math
} // namespace knu

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::vec2<T2> &v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::vec2<T2> &v)
{
	wos << "(" << v.x << ", " << v.y << ")";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::vec3<T2> &v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::vec3<T2> &v)
{
	wos << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::vec4<T2> &v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::vec4<T2> &v)
{
	wos << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::mat2<T2> &m)
{
	os  << m[0] << " " << m[2] << "\n"
		<< m[1] << " " << m[3] << "\n";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::mat2<T2> &m)
{
	wos << m[0] << " " << m[2] << "\n"
		<< m[1] << " " << m[3] << "\n";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::mat3<T2> &m)
{
	os  << m[0] << " " << m[3] << " " << m[6] << "\n"
		<< m[1] << " " << m[4] << " " << m[7] << "\n"
		<< m[2] << " " << m[5] << " " << m[8] << "\n";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::mat3<T2> &m)
{
	wos << m[0] << " " << m[3] << " " << m[6] << "\n"
		<< m[1] << " " << m[4] << " " << m[7] << "\n"
		<< m[2] << " " << m[5] << " " << m[8] << "\n";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::mat4<T2> &m)
{
	os  << m[0] << " " << m[4] << " " << m[8] << " " << m[12] << "\n"
		<< m[1] << " " << m[5] << " " << m[9] << " " << m[13] << "\n"
		<< m[2] << " " << m[6] << " " << m[10] << " " << m[14] << "\n"
		<< m[3] << " " << m[7] << " " << m[11] << " " << m[15] << "\n";
		
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::mat4<T2> &m)
{
	wos << m[0] << " " << m[4] << " " << m[8] << " " << m[12] << "\n"
		<< m[1] << " " << m[5] << " " << m[9] << " " << m[13] << "\n"
		<< m[2] << " " << m[6] << " " << m[10] << " " << m[14] << "\n"
		<< m[3] << " " << m[7] << " " << m[11] << " " << m[15] << "\n";
	return wos;
}

#endif // KNU_MATHLIBRARY6_HPP