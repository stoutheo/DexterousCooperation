/*******************************************************************************

  Copyright (c) by Honda Research Institute Europe GmbH

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

  3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef RCS_HOLOGRAPH_H
#define RCS_HOLOGRAPH_H

#include "HoloNetworkConnection.h"
#include "ComponentBase.h"

#include <Rcs_graph.h>
#include <PeriodicCallback.h>

#include <algorithm>
#include <string>
#include <mutex>
#include <vector>


namespace Rcs
{

class HoloGraph : public ComponentBase, public PeriodicCallback
{
public:

  HoloGraph(EntityBase* parent, const RcsGraph* graph, int port=26794);
  virtual ~HoloGraph();

private:

  // Thread callback function, should be called with networking frequency
  void callback();

  // Events
  void onStart();
  void onStop();
  void onFwdKinematics(RcsGraph* graph_);

  // Members
  RcsGraph* graph;
  HoloNetworkConnection holoConn;
  mutable std::mutex mtx;
  int port;

  // Avoid copying this class
  HoloGraph(const HoloGraph&);
  HoloGraph& operator=(const HoloGraph&);
};

}

#endif   // RCS_HOLOGRAPH_H
