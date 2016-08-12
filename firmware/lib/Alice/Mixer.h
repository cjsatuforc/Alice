/** @file */

#ifndef _ALICE_MIXER_H_
#define _ALICE_MIXER_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "AliceObjectList.h"
#include "MixerChannel.h"

/**
 * @class Mixer
 * @brief A channel mixer that takes values from IInput devices and produces
 *        outputs for IOutput devcies.
 */
class Mixer : public AliceObject
{
public:
  Mixer(char *name, size_t numChannels);
  virtual ~Mixer();

  bool addChannel(channelnumber_t idx, MixerChannel *item);
  MixerChannel *getChannel(channelnumber_t idx);
  size_t numChannels() const;

  cevalue_t evaluate(channelnumber_t idx) const;

  size_t fillOutputArrayZeroCentre(cevalue_t *output, size_t len) const;
  size_t fillOutputArrayTiming(usvalue_t *output, size_t len) const;

private:
  AliceObjectList m_channels; //!< Mixer channels
};

#endif
