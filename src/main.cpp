#include <stdint.h>
#include <math.h>
#include <stdlib.h>
//#include "vec.h"
/*
 * Vector.h
 *
 *  Created on: 05/04/2012
 *      Author: tom
 *      Purpose: To play the part of a mutable array in the absence of the STL.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define SWAP(type, a, b)                                                       \
  type tmp##a = a;                                                             \
  a = b;                                                                       \
  b = tmp##a;

template <class ParameterType> class Predicate {
public:
  virtual void operator()(ParameterType &param) = 0;
};

template <class VectorType> class Vector {
  // The address of the first element of the vector
  VectorType *begin;
  // The address one after the last allocated entry in the underlying array
  VectorType *storage;
  // The index of the most recent element put in the underlying array - the head
  int head;

public:
  // The value that is returned when the caller asks for an element that is out
  // of the bounds of the vector
  VectorType OB;

  // We can save a few re-sizings if we know how large the array is likely to
  // grow to be
  Vector(int initialSize = 0) {
    begin =
        new VectorType[initialSize]; // points to the beginning of the new array
    head = initialSize - 1;
    storage = begin + initialSize; // points to the element one outside of the
                                   // array (such that end - begin = capacity)
  }

  Vector(Vector &obj) {
    begin =
        new VectorType[0]; // Points to the beginning of the new array, it's
                           // zero but this line keeps malloc from seg faulting
                           // should we delete begin before resizing it
    head = -1;
    storage = begin; // points to the element one outside of the array (such
                     // that end - begin = capacity)

    *this = obj;
  }

  // If there's anything in the vector then delete the array, if there's no
  // array then doing will will cause seg faults
  virtual ~Vector() { delete[] begin; }

  Vector &operator=(Vector &obj) {
    // Reallocate the underlying buffer to the same size as the
    Resize(obj.Size());

    for (int i = 0; i < obj.Size(); i++)
      (*this)[i] = obj[i];

    head = obj.head;

    return *this;
  }

  void ForEach(Predicate<VectorType> &functor) {
    for (int i = 0; i < Size(); i++)
      functor(begin[i]);
  }

  // Swaps the underlying array and characteristics of this vector with another
  // of the same type, very quickly
  void Swap(Vector &obj) {
    SWAP(int, head, obj.head);
    SWAP(VectorType *, begin, obj.begin);
    SWAP(VectorType *, storage, obj.storage);
  }

  // Checks the entire Vector to see whether a matching item exists. Bear in
  // mind that the VectorType might need to implement equality operator
  // (operator==) for this to work properly.
  bool Contains(VectorType element) {
    for (int i = 0; i < Size(); i++)
      if (operator[](i) == element)
        return true;

    return false;
  }

  int Find(VectorType element) {
    for (int i = 0; i < Size(); i++)
      if (operator[](i) == element)
        return i;

    return -1;
  }

  void PushBack(VectorType element) { PushBack(&element, 1); }

  void PushBack(const VectorType *elements, int len) {
    // If the length plus this's size is greater than the capacity, reallocate
    // to that size.
    if (len + Size() > Capacity())
      ReAllocate(MAX(Size() + len, Size() * 2));

    int append = MIN(storage - begin - head - 1, len), prepend = len - append;

    // memcpy the data starting at the head all the way up to the last element
    // *(storage - 1)
    memcpy((begin + head + 1), elements, sizeof(VectorType) * append);

    // If there's still data to copy memcpy whatever remains, starting at the
    // first element *(begin) until the end of data. The first step will have
    // ensured that we don't crash into the tail during this process.
    memcpy(begin, (elements + append), sizeof(VectorType) * prepend);

    // Re-recalculate head and size.
    head += len;
  }

  void Erase(unsigned int position) { Erase(position, position + 1); }

  // Erase an arbitrary section of the vector from first up to last minus one.
  // Like the stl counterpart, this is pretty labour intensive so go easy on it.
  void Erase(int first, int last) {
    // For this we'll set the value of the array at first to the value of the
    // array at last plus one. We'll do that all the way up to toIndex
    for (int i = 0; i < (Size() - first); i++) {
      // If by trying to fill in the next element with the ones ahead of it
      // we'll be running off the end of the vector, stop.
      if ((i + last) > (Size() - 1))
        break;

      begin[first + i] = begin[last + i];
    }

    // Adjust the head to reflect the new size
    head -= last - first;
  }

  // Remove the most recent element in the array
  void PopBack() {
    if (Size() > 0)
      head--;
  }

  // Empty the vector, or to be precise - forget the fact that there was ever
  // anything in there.
  void Clear() { head = -1; }

  // Returns a bool indicating whether or not there are any elements in the
  // array
  bool Empty() { return head == -1; }

  // Returns the oldest element in the array (the one added before any other)
  VectorType const &Back() { return *begin; }

  // Returns the newest element in the array (the one added after every other)
  VectorType const &Front() { return begin[head]; }

  // Returns the nth element in the vector
  VectorType &operator[](int n) {
    if (n < Size())
      return begin[n];
    else
      return OB;
  }

  // Returns a pointer such that the vector's data is laid out between ret to
  // ret + size
  VectorType *Data() { return begin; }

  // Recreates the vector to hold len elements, all being copies of val
  void Assign(int len, const VectorType &val) {
    delete[] begin;

    // Allocate an array the same size as the one passed in
    begin = new VectorType[len];
    storage = begin + len;

    // Refresh the head and tail, assuming the array is in order, which it
    // really has to be
    head = len - 1;

    for (int i = 0; i < Size(); i++)
      begin[i] = val;
  }

  // Recreates the vector using an external array
  void Assign(VectorType *array, int len) {
    delete[] begin;

    // Allocate an array the same size as the one passed in
    begin = new VectorType[len];
    storage = begin + len;

    // Refresh the head and tail, assuming the array is in order, which it
    // really has to be
    head = len - 1;

    // Copy over the memory
    memcpy(begin, array, sizeof(VectorType) * len);
  }

  // Returns the number of elements that the vector will support before needing
  // resizing
  int Capacity() { return (storage - begin); }

  // Returns the number of elements in vector
  int Size() { return head + 1; }

  // Requests that the capacity of the allocated storage space for the elements
  // of the vector be at least enough to hold size elements.
  void Reserve(unsigned int size) {
    if (size > Capacity())
      ReAllocate(size);
  }

  // Resizes the vector
  void Resize(unsigned int size) {
    // If necessary, resize the underlying array to fit the new size
    if (size > Capacity())
      ReAllocate(size);

    // Now revise the head and size (tail needn't change) to reflect the new
    // size
    head = size - 1;
  }

private:
  void ReAllocate(unsigned int size) {
    // Just in case we're re-allocating less room than we had before, make sure
    // that we don't overrun the buffer by trying to write more elements than
    // are now possible for this vector to hold.
    if (Size() > (int)size)
      head = size - 1;

    // Allocate an array twice the size of that of the old
    VectorType *_begin = new VectorType[size];
    VectorType *_storage = _begin + size;

    int _head = Size() - 1;

    // Copy across all the old array's data and rearrange it!
    for (int i = 0; i < Size(); i++)
      _begin[i] = (*this)[i];

    // Free the old memory
    delete[] begin;

    // Redirect the old array to point to the new one
    begin = _begin;
    storage = _storage;
    head = _head;
  }
};

#endif // VECTOR_H

uint16_t width = 320, height = 240;
uint16_t sqVis = 30 * 30;
uint16_t maxSpeed = 8;
float maxForce = 0.2;

uint16_t align = 1;
uint16_t seperate = 1;
uint16_t cohere = 1;
bool bounce = 0;

float randMapped(){
    return(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}

struct v2d{
    //Create an empty vector
    v2d(){x = 0.0f; y = 0.0f;}
    //Create a vector from _x and _y
    v2d(const float _x, const float _y) : x(_x), y(_y) {}
    //Create a new vector from frm
    v2d(const v2d& frm) : x(frm.x), y(frm.y) {}
    //Set vector to _x and _y
    v2d set(float _x, float _y) {x = _x; y = _y; return(*this);}
    //Randomize this vector
    v2d randomize(float scale = 1) { float r = randMapped() * 2 * 3.14; set(cos(r) * scale, sin(r) * scale); return(*this); }
    //Set vector to zero
    void zero() {x = 0.0f; y = 0.0f;}
    
    v2d operator + (const v2d& r) {return v2d(this -> x + r.x, this -> y + r.y);}
    v2d operator + (const float r) {return v2d(this -> x + r, this -> y + r);}
    v2d operator += (const v2d& r) {this -> x += r.x; this -> y += r.y; return(*this);}

    v2d operator - (const v2d& r) {return v2d(this -> x - r.x, this -> y - r.y);}
    v2d operator - (const float r) {return v2d(this -> x - r, this -> y - r);}
    v2d operator -= (const v2d& r) {this -> x -= r.x; this -> y -= r.y; return(*this);}


    v2d operator * (const v2d& r) {return v2d(this -> x * r.x, this -> y * r.y);}
    v2d operator * (const float r) {return v2d(this -> x * r, this -> y * r);}
    v2d operator *= (const v2d& r) {this -> x *= r.x; this -> y *= r.y; return(*this);}


    v2d operator / (const v2d& r) {return v2d(this -> x / r.x, this -> y / r.y);}
    v2d operator / (const float r) {return v2d(this -> x / r, this -> y / r);}
    v2d operator /= (const v2d& r) {this -> x /= r.x; this -> y /= r.y; return(*this);}

    v2d norm() {*this = *this/len(); return(*this);}
    v2d setLen(float mag) {*this = *this/len() * mag; return(*this);}
    float len() {return(hypotf(x, y));}
    float sqrLen() {return(x * x + y * y);}
    float sqrDist(const v2d& b) { v2d a = *this - b; return(a.x * a.x + a.y * a.y);  }

    v2d limit(float b)
    {
        if(sqrLen() <= b * b){
            return(*this);
        }
        setLen(b);
        return(*this);
    }
    
    float x;
    float y;
};
typedef v2d*    vec_v2d;
//struct neighbor{
//    neighbor() { index = 0; }
//    neighbor(uint16_t _index) : index(_index) {}
//    neighbor(uint16_t _index, Vector<float> _dists) : index(_index), dists(_dists) {}
//    neighbor(const neighbor& frm) {}
//    bool operator == (neighbor compare) {return(this -> index == compare.index);}
//    uint16_t index;
//    Vector <float> dists;
//};
struct Boid{
    Boid(uint16_t _index) {
        index = _index;
        pos = v2d(rand() % width, rand() % height);
        vel.randomize(maxSpeed);
    }
    bool operator == (const Boid& compare) 
    {
        return(this -> index == compare.index);
    }
    uint16_t index;
    v2d pos;
    v2d vel;
    v2d acc;
    v2d aln;
    v2d csn;
    v2d sep;
    Vector <uint16_t> neighbors;
    Vector <float> dists;

    void flock(Vector <Boid*>& boids){
        uint16_t total = 0;
        acc.zero();
        aln.zero();
        csn.zero();
        sep.zero();
        neighbors.Clear();
        dists.Clear();

		for (uint16_t i = 0; i < boids.Size(); i++) {
			if (boids[i] == this) {continue;}
            float d;
            auto l = boids[i];
			if (index > boids[i]->index) {
				int j = boids[i]->neighbors.Find(index);
//                std::cout << j << ',' << index << ',' << boids[i] -> index <<','<< i<<'\n';
				if (j + 1) {
					d = boids[i]->dists[j];
				} else continue;
			} else d = pos.sqrDist(boids[i]->pos);

            if (d <= sqVis) {
                auto v = boids[i];
                auto v2 = v->dists;
				neighbors.PushBack(index);
				dists.PushBack(d);
                aln += boids[i]->vel;
                csn += boids[i]->pos;

				sep = (sep + (pos - boids[i]->pos)) * 1 / d;

				
				total++;
			}
        }

        if (total > 0) {
            aln.setLen(maxSpeed);
            aln -= vel;
            aln.limit(maxForce);

            csn = (csn * 1/total) - pos;
            csn.setLen(maxSpeed);
            csn -= vel;
            csn.limit(maxForce);

            sep.setLen(maxSpeed);
            sep -= vel;
            sep.limit(maxForce);
		}
        acc = (acc + aln) * align;
        acc = (acc + csn) * cohere;
        acc = (acc + sep) * seperate;
    }

    void update() {
        vel += acc;
        vel.limit(maxSpeed);
        pos += vel;

        if (bounce) {
            //bool ran = false;
            //if (pos.x] < 0 || pos.x > width) {
            //    ran = true;
            //    vel.x *= -1;
            //}
            //if (pos.y < 0 || pos.y > height) {
            //    ran = true;
            //    vel.y *= -1;
            //}
            //if (ran) {
            //    this.pos[0] = constrain(this.pos[0], 0, width);
            //    this.pos[1] = constrain(this.pos[1], 0, height);
            //}
        }
        else {
            if (pos.x < 0) pos.x = width;
            if (pos.x > width) pos.x = 0;
            if (pos.y < 0) pos.y = height;
            if (pos.y > height) pos.y = 0;
        }
    }

};



int main(void)
{
    //srand((unsigned int)rtc_Time());
    Vector<Boid*> flock;
    for (uint16_t i = 0; i < 150; i++) {
        flock.PushBack(new Boid(i));
    }
    auto v = flock[1];
    auto h = flock[149];
    while (1) {
        for (uint16_t i = 1; i < 149; i++) {
            Boid temp = *flock[i];
            flock[i]->flock(flock);
        }
        for (uint16_t i = 1; i < 149; i++) {
            flock[i]->update();
        }
        //std::cout << flock[30]->pos.x << '\n';
    }
}
